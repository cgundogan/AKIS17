#include "board.h"
#include "xtimer.h"
#include "periph/pwm.h"

#define MODE    PWM_LEFT
#define FREQ    (1000U)
#define RES     (1000U)
#define STEPS   (10U)

int main(void)
{
    int state = 0;

    pwm_init(PWM_DEV(0), MODE, FREQ, RES);
    pwm_set(PWM_DEV(0), 0, RES); // max. Tastgrad für blaue LED
    pwm_set(PWM_DEV(0), 1, RES); // max. Tastgrad für grüne LED

    while(1) {
        pwm_set(PWM_DEV(0), 2, state); // variierender Tastgrad für rote LED
        state = (state + STEPS) % RES;
        xtimer_usleep(10 * 1000);
    };

    return 0;
}
