#ifndef ACTUATOR_COMMANDS_H
#define ACTUATOR_COMMANDS_H

#include "generalTypes.h"

/* =================================================
*  Define types
*  ================================================= */
typedef struct t_actuatorStruct {
    void * openGate;
    void * closeGate;
};

/* =================================================
*  Define public interrupt function prototypes
*  ================================================= */
t_error plugActuatorCommands(void * p_openGateFunction, void * p_closeGateFunction);

t_actuatorStruct getActuatorObject(void);

#endif /* ACTUATOR_COMMANDS_H */