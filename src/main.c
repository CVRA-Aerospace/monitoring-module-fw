#include <ch.h>
#include <hal.h>

static THD_WORKING_AREA(led_thread, 128);
static THD_FUNCTION(led_thread_main, arg) {
    (void)arg;
    chRegSetThreadName("LED");

    palSetPadMode(GPIOA, GPIOA_ERROR_LED, PAL_MODE_OUTPUT_PUSHPULL);    

    while (1) {
        palSetPad(GPIOA, GPIOA_ERROR_LED);
        chThdSleepMilliseconds(80);
        palClearPad(GPIOA, GPIOA_ERROR_LED);
        chThdSleepMilliseconds(80);
        palSetPad(GPIOA, GPIOA_ERROR_LED);
        chThdSleepMilliseconds(80);
        palClearPad(GPIOA, GPIOA_ERROR_LED);
        chThdSleepMilliseconds(760);
    }
}

int main(void) {
    halInit();
    chSysInit();

    chThdCreateStatic(led_thread, sizeof(led_thread), NORMALPRIO, led_thread_main, NULL);

    while (1) {
        chThdSleepMilliseconds(1000);
    }
}
