#include "generalTypes.h"
#include "interrupt.h"
#include "virtualTimers.h"

t_virtualTimer s_lineSensorVirtualTimer;

void setup() {
    interruptInitialize(C_LINE_SENSOR_INTERRUPT_PIN, &lineSensorInterruptCallbackIrq);
    interruptInitialize(C_SWITCH_INPUT_INTERRUPT_PIN, &switchInputInterruptHandlerCallbackIrq);

    virtualTimerInit(s_lineSensorVirtualTimer);
}

void loop() {

    do {
        /* Wait for the timer to expire */
    } while (C_VIRTUAL_TIMER_EXPIRED == isVirtualTimerExpired(s_lineSensorVirtualTimer));
    
}
