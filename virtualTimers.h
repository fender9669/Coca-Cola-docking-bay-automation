#ifndef VIRTUAL_TIMERS_H
#define VIRTUAL_TIMERS_H

#include "generalTypes.h"

#define C_VIRTUAL_TIMER_ACTIVE     (C_TRUE)
#define C_VIRTUAL_TIMER_EXPIRED    (C_TRUE)

#define C_LINE_SENSOR_VIRTUAL_TIMER (0)

typedef struct t_virtualTimer {

};

t_virtualTimer g_virtualTimerList[3];

t_error virtualTimerInit(t_virtualTimer p_virtualTimer);

t_bool isVirtualTimerExpired(t_virtualTimer p_virtualTimer);

t_error releaseVirtualTimer(t_virtualTimer p_virtualTimer);

t_virtualTimer getVirtualTimer(t_int32u p_virtualTimerNb);


#endif /* VIRTUAL_TIMERS_H */