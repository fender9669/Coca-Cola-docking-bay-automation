#include "generalTypes.h"
#include "interrupt.h"
#include "virtualTimers.h"

static t_virtualTimer s_lineSensorVirtualTimer;
static t_int32u       s_waitTime = 30 * C_SECONDS_TO_US;

void setup() {
    interruptInitialize(C_LINE_SENSOR_INTERRUPT_PIN, &lineSensorInterruptCallbackIrq);
    interruptInitialize(C_SWITCH_INPUT_INTERRUPT_PIN, &switchInputInterruptHandlerCallbackIrq);

    virtualTimerInit(s_lineSensorVirtualTimer, s_waitTime);
    passTimeVariableToBackend(&s_waitTime);
}

void loop() {

    do {
        /* Wait for the timer to expire */
    } while (C_VIRTUAL_TIMER_EXPIRED == isVirtualTimerExpired(s_lineSensorVirtualTimer));

}
