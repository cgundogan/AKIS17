#include "board.h"
#include "xtimer.h"

int main(void)
{
    while(1) {
        LED0_TOGGLE;
        xtimer_sleep(1);
    };

    return 0;
}
