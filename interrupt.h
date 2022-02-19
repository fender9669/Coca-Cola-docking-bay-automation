#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "generalTypes.h"
#include "virtualTimers.h"

/* =================================================
*  Define interrupt constants
*  ================================================= */

#define C_LINE_SENSOR_INTERRUPT_PIN     (1)
#define C_SWITCH_INPUT_INTERRUPT_PIN    (2)

#define C_SWITCH_INPUT_1                (0)
#define C_SWITCH_INPUT_2                (1)
#define C_SWITCH_INPUT_3                (2)

#define C_SWITCH_INPUT_TIME_10_S        (10 * C_SECONDS_TO_US)
#define C_SWITCH_INPUT_TIME_20_S        (20 * C_SECONDS_TO_US)
#define C_SWITCH_INPUT_TIME_30_S        (30 * C_SECONDS_TO_US)

/* =================================================
*  Define public interrupt function prototypes
*  ================================================= */

t_error interruptInitialize(t_int32u p_interrupt, void *p_interruptFunctionHandler);

void lineSensorInterruptCallbackIrq(void);

void switchInputInterruptHandlerCallbackIrq(void);

void passTimeVariableToBackend(t_int8u *p_timeVariable);

#endif /* INTERRUPT_H */