#include "actuatorCommands.h"

/* =================================================
*  Static variables definition
*  ================================================= */
static t_actuatorStruct s_driversObj;

/* =================================================
*  Public functions implementation
*  ================================================= */
t_error plugActuatorCommands(void * p_openGateFunction, void * p_closeGateFunction) {
    t_error l_error = E_NOK;

    if((p_openGateFunction != C_NULL) && (p_closeGateFunction != C_NULL)) {
        s_driversObj.closeGate = &p_closeGateFunction;
        s_driversObj.openGate  = &p_openGateFunction;
        l_error = E_OK;
    }

    return l_error;
}

t_actuatorStruct getDriversObject(void) {
    return s_driversObj;
}