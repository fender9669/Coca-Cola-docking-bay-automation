#include <Arduino.h>
#include "interrupt.h"

/* =================================================
*  Static variables definition
*  ================================================= */
static t_int32u s_frontendTimeVariable = 0;
static t_int32u s_frontendTimeVariableAddress = 0x0;

/* =================================================
*  Static functions definition
*  ================================================= */
static void changeFrontendTime(p_newTime);

/* =================================================
*  Public functions implementation
*  ================================================= */
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
    t_virtualTimer    l_lineSensorVirtualTimer = getVirtualTimer(C_LINE_SENSOR_VIRTUAL_TIMER);
    getActuatorObject l_driversObject = getDriversObject();

    /* Reset the timer */
    virtualTimerInit(l_lineSensorVirtualTimer);

    /* Send an open command to be sure that the gate stays open */
    l_driversObject.openGate();
}

void switchInputInterruptHandlerCallbackIrq(void) {
    t_int32u l_switchPort = 0;

    switch(l_switchPort) {
    case C_SWITCH_INPUT_1:
        changeFrontendTime(C_SWITCH_INPUT_TIME_10_S);
        break;
    case C_SWITCH_INPUT_2:
        changeFrontendTime(C_SWITCH_INPUT_TIME_20_S);
        break;
    case C_SWITCH_INPUT_3:
        changeFrontendTime(C_SWITCH_INPUT_TIME_30_S);
        break;
    
    default:
        break;
    }
}

void passTimeVariableToBackend(t_int8u *p_timeVariable) {
    s_frontendTimeVariable = p_timeVariable;
    s_frontendTimeVariableAddress = &p_timeVariable;
}

/* =================================================
*  Static functions implementation
*  ================================================= */
static void changeFrontendTime(p_newTime) {
    *s_frontendTimeVariableAddress = p_newTime;
}
