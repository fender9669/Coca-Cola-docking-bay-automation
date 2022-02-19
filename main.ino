#include "generalTypes.h"
#include "interrupt.h"
#include "virtualTimers.h"
#include "actuatorCommands.h"

#define C_GATE_PIN_NB     (13)

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
static t_error sendImpulseToPin(p_pinNb)

void setup() {
    plugActuatorCommands(&sendOpenGateCommand, &sendCloseGateCommand);

    interruptInitialize(C_LINE_SENSOR_INTERRUPT_PIN, &lineSensorInterruptCallbackIrq);
    interruptInitialize(C_SWITCH_INPUT_INTERRUPT_PIN, &switchInputInterruptHandlerCallbackIrq);

    virtualTimerInit(s_lineSensorVirtualTimer, s_waitTime);
    passTimeVariableToBackend(&s_waitTime);

    /* PIN setup */
    pinMode(C_GATE_PIN_NB, OUTPUT);
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
    l_error = sendImpulseToPin(C_GATE_PIN_NB)
    return l_error;
}

static t_error sendOpeneGateCommand(void) {
    t_error l_error = E_NOK;
    l_error = sendImpulseToPin(C_GATE_PIN_NB)
    return l_error;
}

static t_error sendImpulseToPin(p_pinNb) {
    t_error l_error = E_NOK;
    /* Read the current pin state */
    t_bool l_currentPinState = analogRead(p_pinNb);

    digitalWrite(p_pinNb, !l_currentPinState);
    delay(1 * C_SECONDS_TO_US);
    digitalWrite(p_pinNb, l_currentPinState);
    delay(1 * C_SECONDS_TO_US);

    /* Check if the pin has returned to it's original state */
    if(l_currentPinState == analogRead(p_pinNb)) {
        l_error = E_OK;
    }

    return l_error;
}
