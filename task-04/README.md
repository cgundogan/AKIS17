# Task 4: Peripherie Ansteuern

RIOT ermöglicht die Ansteuerung von μC Peripherie, wie z.B. die PWM, ADC, I²C, SPI, UART, ...
In diesem Schritt soll die PWM Ansteuerung näher erläutert werden.

## Task 4.1: Pulse Width Modulation / Pulsweitenmodulation

Um Rechteckpulse zu generieren, wird von der PWM Abstraktion in RIOT die Frequenz des zu generierenden
Signals, die Auflösung des Signals, und der Tastgrad erwartet.

Die bereitgestellten Funktionen zur PWM sind [hier](https://riot-os.org/api/group__drivers__periph__pwm.html) zu finden
und müssen mit der `periph/pwm.h` Datei inkludiert werden:
```C
#include "periph/pwm.h"
```

Um die PWM auf dem Board zu initialisieren, wird folgendes benötigt:
```C
#define FREQ 1000
#define RES  1000

pwm_init(PWM_DEV(0), PWM_LEFT, FREQ, RES);
```

Die Frequenz und die Auflösung sind in dem obigen Beispiel beide auf `1000` gesetzt.
Der Modus zur Flankenlage ist auf `PWM_LEFT` gesetzt.
`PWM_DEV(0)` spricht den ersten PWM-Endpunkt auf dem Board an. Prinzipiell können mehrere auf einem
Board existieren, welche separat initialisert werden müssen.

Mit `pwm_set` kann dann der Tastgrad für einen Channel angegeben werden. Ein PWM-Endpunkt kann hierbei
aus mehreren Channels bestehen.
```C
pwm_set(PWM_DEV(0), 0, 500);
```
Der Tastgrad für Channel `0` des PWM-Endpunkts `PWM_DEV(0)` wurde im obigen Beispiel auf `500` gesetzt.

Mithilfe des PWMs können LEDs mit vordefinierter Frequenz an- und ausgeschaltet werden, was einen
Einfluss auf die Helligkeit der LED hat.
In der Endlosschleife kann der Tastgrad des Channels kontinuierlich verändert werden, um so einen
`Fading`-Effekt für eine bestimmte LED zu erzeugen.

[< Task 3](../task-03) | [Task 5 >](../task-05)
