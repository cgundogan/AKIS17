#include "xtimer.h"

int main(void)
{
    while(1) {
        xtimer_usleep(100 * 1000);
    };

    return 0;
}
