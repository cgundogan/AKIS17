# Task 2: Timer

## Task 2.1: xtimer

Das generelle Timer-Modul in RIOT nennt sich [xtimer](https://riot-os.org/api/group__sys__xtimer.html).
Damit der `xtimer` benutzt werden kann, müssen folgende zwei Änderungen vorgeommen werden

1. Makefile
    - `USEMODULE` definiert die RIOT-Module, die ebenfalls mit kompiliert werden sollen.
    Hier muss das `xtimer` Modul hinzugefügt werden: `USEMODULE += xtimer`.

2. main.c
    - Um die vom `xtimer` bereitgestellten Funktionen nutzen zu können, muss noch `xtimer.h` inkludiert werden.
    Dazu wird wieder ganz oben in der `main.c` Datei folgendes hinzugefügt.

      ```C
      #include "xtimer.h"
      ```

## Task 1.2: LED-Steuerung mit xtimer

Die LEDs können nun periodisch mit niedrigerer Frequenz getoggled werden.
Zum Testen können die Funktionen `xtimer_sleep()` oder `xtimer_usleep()` innerhalb
der Endlosschleife benutzt werden.

Mit den LED Makros aus [Task 1](../task-01) kann nun eine simple Ampelsteuerung programmiert werden.

[< Task 2](../task-02) | [Task 3 >](../task-03)
