#include "virtualTimers.h"

/* =================================================
*  Public functions implementation
*  ================================================= */
t_error virtualTimerInit(t_virtualTimer p_virtualTimer, t_int32u p_waitTime) {
    t_error l_error = E_NOK;


    return l_error;
}

t_bool isVirtualTimerExpired(t_virtualTimer p_virtualTimer) {
    t_bool l_isTimerExpired = C_FALSE;


    return l_isTimerExpired;
}

t_error releaseVirtualTimer(t_virtualTimer p_virtualTimer) {
    t_error l_error = E_NOK;


    return l_error;
}

t_virtualTimer getVirtualTimer(t_int32u p_virtualTimerNb) {
    return g_virtualTimerList[p_virtualTimerNb];
}