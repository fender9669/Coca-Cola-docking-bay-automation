#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "generalTypes.h"

/* =================================================
*  Define interrupt constants
*  ================================================= */

#define C_LINE_SENSOR_INTERRUPT_PIN     (1)
#define C_SWITCH_INPUT_INTERRUPT_PIN    (2)

/* =================================================
*  Define interrupt function prototypes
*  ================================================= */

t_error interruptInitialize(t_int32u p_interrupt, void *p_interruptFunctionHandler);

void lineSensorInterruptCallbackIrq(void);

void switchInputInterruptHandlerCallbackIrq(void);

#endif /* INTERRUPT_H */