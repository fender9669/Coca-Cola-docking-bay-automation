#include "generalTypes.h"
#include "interrupt.h"
#include "virtualTimers.h"
#include "actuatorCommands.h"

/* =================================================
*  Static variables definition
*  ================================================= */
static t_virtualTimer s_lineSensorVirtualTimer;
static t_int32u       s_waitTime = 30 * C_SECONDS_TO_US;

/* =================================================
*  Static functions definition
*  ================================================= */
static t_error sendCloseGateCommand(void);
static t_error sendOpenGateCommand(void);

void setup() {
    plugActuatorCommands(&sendOpenGateCommand, &sendCloseGateCommand);

    interruptInitialize(C_LINE_SENSOR_INTERRUPT_PIN, &lineSensorInterruptCallbackIrq);
    interruptInitialize(C_SWITCH_INPUT_INTERRUPT_PIN, &switchInputInterruptHandlerCallbackIrq);

    virtualTimerInit(s_lineSensorVirtualTimer, s_waitTime);
    passTimeVariableToBackend(&s_waitTime);
}

void loop() {

    do {
        /* Wait for the timer to expire */
    } while (C_VIRTUAL_TIMER_ACTIVE == isVirtualTimerExpired(s_lineSensorVirtualTimer));

    if (E_OK == sendCloseGateCommand()) {
        releaseVirtualTimer(s_lineSensorVirtualTimer);
    }
}

/* =================================================
*  Static functions implementation
*  ================================================= */
static t_error sendCloseGateCommand(void) {
    t_error l_error = E_NOK;

    return l_error;
}

static t_error sendOpeneGateCommand(void) {
    t_error l_error = E_NOK;

    return l_error;
}
