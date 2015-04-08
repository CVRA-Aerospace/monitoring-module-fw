#include <ch.h>
#include <hal.h>

static THD_WORKING_AREA(led_thread_wa, 128);
static THD_FUNCTION(led_thread, arg) {
    (void)arg;
    chRegSetThreadName("LED");
    while (1) {
        palSetPad(GPIOA, GPIOA_HEARTBEAT_LED);
        chThdSleepMilliseconds(80);
        palClearPad(GPIOA, GPIOA_HEARTBEAT_LED);
        chThdSleepMilliseconds(80);
        palSetPad(GPIOA, GPIOA_HEARTBEAT_LED);
        chThdSleepMilliseconds(80);
        palClearPad(GPIOA, GPIOA_HEARTBEAT_LED);
        chThdSleepMilliseconds(760);
    }
    return 0;
}

void panic_hook(const char *reason) {
    (void)reason;
    while (1) {
        int i;
        for (i = 0; i < 500000; i++) {
            __asm__ volatile ("nop":::);
        }
        palTogglePad(GPIOA, GPIOA_HEARTBEAT_LED);
    }
}

int main(void) {
    halInit();
    chSysInit();
    chThdCreateStatic(led_thread_wa, sizeof(led_thread_wa), NORMALPRIO, led_thread, NULL);

    while (1) {
        chThdSleepMilliseconds(1000);
    }
}
