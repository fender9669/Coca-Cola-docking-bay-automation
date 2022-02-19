#ifndef VIRTUAL_TIMERS_H
#define VIRTUAL_TIMERS_H

#include "generalTypes.h"

/* =================================================
*  Define constants
*  ================================================= */
#define C_SECONDS_TO_US            (1000)

#define C_VIRTUAL_TIMER_ACTIVE     (C_FALSE)
#define C_VIRTUAL_TIMER_EXPIRED    (C_TRUE)

#define C_LINE_SENSOR_VIRTUAL_TIMER (0)

/* =================================================
*  Define types
*  ================================================= */
typedef struct t_virtualTimer {

};

/* =================================================
*  Define global variables
*  ================================================= */
t_virtualTimer g_virtualTimerList[3];

/* =================================================
*  Define public interrupt function prototypes
*  ================================================= */
t_error virtualTimerInit(t_virtualTimer p_virtualTimer, t_int32u p_waitTime);

t_bool isVirtualTimerExpired(t_virtualTimer p_virtualTimer);

t_error releaseVirtualTimer(t_virtualTimer p_virtualTimer);

t_virtualTimer getVirtualTimer(t_int32u p_virtualTimerNb);


#endif /* VIRTUAL_TIMERS_H */