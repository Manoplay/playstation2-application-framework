//
// Created by Alessandro Mascolo on 28/06/24.
//

#include "PAFTimer.h"

static unsigned long timer_callback(int id, unsigned long scheduled_time, unsigned long actual_time, void *arg, void *pc_value);

Timer::Timer(int time) {
//    InitializeTimerAlarm(&intimer);
    intimer = SetTimerAlarm(MSec2TimerBusClock(time), reinterpret_cast<timer_alarm_handler_t>(&timer_callback), &flag);
}

bool Timer::Check() const {
    return flag;
}

void Timer::Stop() {
    flag = false;
    ReleaseTimerAlarm(intimer);
}

unsigned long timer_callback(int id, unsigned long scheduled_time, unsigned long actual_time, void *arg, void *pc_value) {
    *(bool*)arg = true;
    ReleaseTimerAlarm(id);
    return 0;
}
