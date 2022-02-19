#include <Arduino.h>
#include "interrupt.h"
#include "virtualTimers.h"

t_error interruptInitialize(t_int32u p_interrupt, void *p_interruptFunctionHandler) {
    t_error l_error = E_NOK;

    if ((p_interrupt != 0) && (p_interruptFunctionHandler != C_NULL)) {
        attachInterrupt(p_interrupt, p_interruptFunctionHandler, RISING);
        l_error = E_OK;
    } else {
        l_error = E_NOK;
    }

    return l_error;
}

void lineSensorInterruptCallbackIrq(void) {
    t_virtualTimer l_lineSensorVirtualTimer = getVirtualTimer(C_LINE_SENSOR_VIRTUAL_TIMER);
    virtualTimerInit(l_lineSensorVirtualTimer);
}

void switchInputInterruptHandlerCallbackIrq(void) {

}