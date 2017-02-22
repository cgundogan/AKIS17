# Task 1: Und es ward LED

## Task 1.1: Grundgerüst

Dieser Schritt soll die Ordnerstruktur und die benötigten Dateien bekannt machen.

Eine Applikation, die RIOT benutzt, benötigt im einfachsten Fall **zwei** Dateien:

1. **Makefile** - diese Datei integriert die Applikation in RIOTs Build-System
2. **main.c** - Eine `C` Datei mit einer validen `main()` Funktion

Ein Minimalbeispiel für beide Dateien ist jeweils in [Makefile](Makefile) und [main.c](main.c) gegeben.

### Makefile
- `APPLICATION` definiert den Applikationsnamen und wird zur Bennenung der Kompilate verwendet.
- `BOARD` bestimmt, für welches Board das Projekt gebaut werden soll.
   Die Liste der validen `BOARD` Einträge kann mit `make info-boards-supported` abgefragt werden.
   In dem Minimalbeispiel wird das `BOARD` auf `pba-d-01-kw2x` gesetzt, sofern es nicht vom Aufrufer
   überschrieben wird.
- `include` inkludiert das RIOT Build-System in das eigene. Der übergebene Pfad muss auf ein
   existierendes RIOT-Verzichnis zeigen.

### main.c
- Eine valide `main()` Funktion mit folgender Signatur muss enthalten sein.
```C
int main(void)
{
...
}
```
- Die `main` Funktion im μC sollte sich nicht beenden, um einen andauernden Betrieb zu gewährleisten.
  In dem Minimalbeispiel wird mit einer Endlosschleife `while(1) { };` dafür gesorgt, dass das Programm nicht terminiert.
- Syntaktisch wird jedoch ebenfalls die `return` Anweisung erwartet.

Um das Programm zu kompilieren und es dann auf das Board zu *flashen*, wird folgender Befehl benötigt:
```sh
make all flash
```

## Task 1.2: LED-Steuerung

Dieser Schritt soll die Ansteuerungen von *onboard* LEDs darstellen.

- LED-Definitionen für das jeweilige Board sind in der Dokumentation zu finden.
    Beispielsweise existieren für das PhyWave Board **drei** LED-Definitionen.
    Die Dokumentation ist [hier](https://riot-os.org/api/group__board__phywave__eval.html) zu finden.
    Das Board besitzt eine RGB LED, in der alle drei Farben einzeln adressierbar sind.
    - `LED0` - Rot
    - `LED1` - Grün
    - `LED2` - Blau

    Um die LED-Definitionen nutzen zu können, muss die `board.h` Datei ganz oben in der `main.c` inkludiert werden:

    ```C
    #include "board.h"
    ```

- Zur Steuerung der LEDs werden spezielle Makros vordefiniert.
    - `LEDX_ON` schaltet die LED X an.
    - `LEDX_OFF` schaltet die LED X aus.
    - `LEDX_TOGGLE` schaltet die LED X an/aus.

- Beispielhaft kann die `while`-Schleife in [main.c](main.c) mit `LED0_ON;` befüllt werde.
- Zum erneuten Kompilieren und Flashen wird wieder folgender Befehl verwendet:

    ```sh
    make all flash
    ```
[Task 2 >](../task-02)
