# Task 5: Shell-Interaktion

RIOT bietet eine rudimentäre Shell zur Interaktion mit dem Board an.

Die interaktive Kommandoeingabe wird folgendermaßen aktiviert:

1. Makefile

    ```make
    USEMODULE += shell
    USEMODULE += shell_commands
    ```
2. main.c

    ```C
    #include "shell.h"
    #include "shell_commands.h"
    ```

Weitere Informationen zur Shell gibt es [hier](https://riot-os.org/api/group__sys__shell.html).

Zur Benutzung der Shell muss ein `char` Buffer mit der Größe `SHELL_DEFAULT_BUFSIZE` erstellt werden.
```C
char line_buf[SHELL_DEFAULT_BUFSIZE];
```
Dieser Buffer wird dann der `shell_run()` Funktion übergeben, um die Shell zu aktivieren.
```C
shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);
```

Aufallend ist, dass nun keine Endlosschleife `while(1){ };` mehr benötigt wird.
Der `shell_run()` Aufruf enthält bereits eine Endlosschleife, was ebenfalls zur Folge hat,
dass Programmcode nach diesem Aufruf niemals erreicht wird.

Um sich mit der Shell zu verbinden, kann nach dem Kompilieren und Flashen das Kommando `make term`
aufgerufen werden. Die Befehle können auch mit einer Befehlszeile ausgeführt werden:
```sh
make all flash term
```

## Task 5.1: Modulbasierte Shell-Kommandos

Modulbasierte Shell-Kommandos werden automatisch aktiviert, wenn die Shell aktiviert ist und die jeweiligen
Module in der `USEMODULE` Variable stehen (und diese denn Shell-Kommandos anbieten).

Um alle aktivierten Shell-Kommandos zu sehen, kann man sich mit `make term` wieder einwählen und
```
help
```
eintippen.

Dies ist eine exemplarische Ausgabe:
```
2017-02-22 12:14:54,828 - INFO #  main(): This is RIOT! (Version: 2017.04-devel-211-g8d207c)
2017-02-22 12:14:54,829 - INFO # Welcome to RIOT
> help
2017-02-22 12:14:56,831 - INFO #  help
2017-02-22 12:14:56,834 - INFO # Command              Description
2017-02-22 12:14:56,837 - INFO # ---------------------------------------
2017-02-22 12:14:56,840 - INFO # reboot               Reboot the node
> 
```

Zum Hinzufügen der shell Kommandos für das `random` und das `ps` Modul müssen diese zur
`USEMODULE` Variable hinzugefügt werden:
```make
USEMODULE += random
USEMODULE += ps
```

Nun sieht die Ausgabe folgendermaßen aus:
```
2017-02-22 12:18:19,348 - INFO #  main(): This is RIOT! (Version: 2017.04-devel-211-g8d207c)
2017-02-22 12:18:19,349 - INFO # Welcome to RIOT
> help
2017-02-22 12:18:20,975 - INFO #  help
2017-02-22 12:18:20,977 - INFO # Command              Description
2017-02-22 12:18:20,981 - INFO # ---------------------------------------
2017-02-22 12:18:20,984 - INFO # reboot               Reboot the node
2017-02-22 12:18:20,989 - INFO # ps                   Prints information about running threads.
2017-02-22 12:18:20,993 - INFO # random_init          initializes the PRNG
2017-02-22 12:18:20,998 - INFO # random_get           returns 32 bit of pseudo randomness
>
```

## Task 5.2: Eigenes Shell-Kommando

In RIOT können auch eigene Shell-Kommandos geschrieben und registriert werden.
Dafür wird eine Funktion mit der Signatur
```C
int led(int argc, char **argv);
```
benötigt.

`argc` gibt die Anzahl der an dieses Shell-Kommando übergebenen Parameter an, während `argv` einen
Pointer auf die übergebenen Parameter darstellt.

Ein einfaches Shell-Kommando zum Togglen der LED ist folgend gegeben:
```C
int led(int argc, char **argv)
{
	if (atoi(argv[1]) == 0) {
		LED0_TOGGLE;
	}
	else if (atoi(argv[1]) == 1) {
		LED1_TOGGLE;
	}
	else if (atoi(argv[1]) == 2) {
		LED2_TOGGLE;
	}
	else {
		return -1;
	}

	return 0;
}
```

Hinweis: für `atoi()` wird das Inkludieren von `stdlib.h` benötigt:
```C
#include <stdlib.h>
```

Nachdem diese Funktion definiert wurde, muss sie noch dem Shell-Handler bekannt gemacht werden.
Dazu muss diese Funktion in ein `shell_command_t` struct Array hinterlegt werden, welches dann der
`shell_run` Funktion übergeben wird.
```C
static const shell_command_t shell_cmds[] = {
	{ "led", "toggle with led <num>", led },
	{ NULL, NULL, NULL}
};
```
Danach wird dieses Array der `shell_run` in der `main()` Funktion übergeben:
```C
shell_run(shell_cmds, line_buf, SHELL_DEFAULT_BUFSIZE);
```

[< Task 4](../task-04)
