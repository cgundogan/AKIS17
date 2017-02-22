# Task 3: Sensoren Auslesen

Das PhyWave Board besitzt einige onboard Sensoren, die wir mit Hilfe von RIOT auslesen und ausgeben können.
[Hier](https://riot-os.org/api/group__board__phywave__eval.html) gibt es einen Hinweis zu allen
definierten Sensoren für das benutzte Board.

## Task 3.1: Beschleunigungssensor

Das PhyWave besitzt einen 3-Achsen Beschleunigungssensor mit der Produktbezeichnung `MMA8652`.
RIOT besitzt einen [Treiber](https://riot-os.org/api/group__drivers__mma8x5x.html) für diesen
Sensor und dieser kann folgendermaßen aktiviert werden:

1. Makefile
    - Das Modul muss zu der `USEMODULE` Variable hinzugefügt werden.

      ```make
      USEMODULE += mma8x5x
      ```
2. main.c
    - Die `mma8x5x.h` Datei enthält die definierten Treiber-Funktionen und muss inkludiert werden.
    - Die `mma8x5x_params.h` enthält Board-spezifische Parameter für diesen Sensor und muss ebenfalls inkludiert werden.

      ```C
      #include "mma8x5x.h"
      #include "mma8x5x_params.h"
      ```

Initialisiert wird der Treiber mit der `mma8x5x_init()` Funktion. Dafür wird ein `mma8x5x_t` struct benötigt:
```C
mma8x5x_t dev;
mma8x5x_init(&dev, mma8x5x_params);
```
Die `mma8x5x_params` Variable wurde in der inkludierten `mma8x5x_params.h` Datei definiert.

Die Ergebnisse des Sensors werden in einem `mma8x5x_data_t` struct gespeichert, also muss auch dieser
noch angelegt werden:
```C
mma8x5x_data_t data;
```

Ausgelesen wird der Sensor mit der `mma8x5x_read()` Funktion.
So können, innerhalb der Endlosschleife, die Werte ausgelesen und dem Benutzer angezeigt werden.
Zur Ausgabe an den Benutzer wird noch ein weiterer Include in der `main.c` benötigt:
```C
#include <stdio.h>
```

Ausgelesen wird das dann folgendermaßen:
```C
mma8x5x_read(&dev, &data);
printf("Acceleration [in mg]: X: %d Y: %d Z: %d\n", data.x, data.y, data.z);
```

## Task 3.2: Farblichtsensor

Das PhyWave besitzt einen RGB Farblichtsensor mit der Produktbezeichnung `TCS3772`.
RIOT besitzt einen [Treiber](https://riot-os.org/api/group__drivers__tcs37727.html) für diesen
Sensor und dieser kann folgendermaßen aktiviert werden:

1. Makefile
    - Das Modul muss zu der `USEMODULE` Variable hinzugefügt werden.

      ```make
      USEMODULE += tcs37727
      ```
2. main.c
    - Die `tcs37727.h` Datei enthält die definierten Treiber-Funktionen und muss inkludiert werden.
    - Die `tcs37727_params.h` enthält Board-spezifische Parameter für diesen Sensor und muss ebenfalls inkludiert werden.

      ```C
      #include "tcs37727.h"
      #include "tcs37727_params.h"
      ```

Initialisiert wird der Treiber mit der `tcs37727_init()` Funktion. Dafür wird ein `tcs37727_t` struct benötigt:
```C
tcs37727_t dev;
tcs37727_init(&dev, tcs37727_params);
```
Die `tcs37727_params` Variable wurde in der inkludierten `tcs37727_params.h` Datei definiert.

Die Ergebnisse des Sensors werden in einem `tcs37727_data_t` struct gespeichert, also muss auch dieser
noch angelegt werden:
```C
tcs37727_data_t data;
```

Ausgelesen wird der Sensor mit der `tcs37727_read()` Funktion:
```C
tcs37727_read(&dev, &data);
printf("R: %lu G: %lu B: %lu CT: %lu Lux: %lu\n", data.red, data.green, data.blue, data.ct, data.lux);
```

[< Task 2](../task-02) | [Task 4 >](../task-04)
