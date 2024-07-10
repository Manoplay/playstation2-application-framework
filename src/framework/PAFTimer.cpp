//
// Created by Alessandro Mascolo on 28/06/24.
//

#include "PAFTimer.h"

static void timer_callback(struct timer_alarm_t *alarm, void *arg);

Timer::Timer(int time) {
    InitializeTimerAlarm(&intimer);
    SetTimerAlarm(&intimer, MSec2TimerBusClock(time), &timer_callback, &flag);
}

bool Timer::Check() const {
    return flag;
}

void Timer::Retime(int newTime) {
    SetTimerAlarm(&intimer, MSec2TimerBusClock(newTime), &timer_callback, &flag);
}

void Timer::Start() {
    flag = false;
    StartTimerAlarm(&intimer);
}

void Timer::Stop() {
    flag = false;
    StopTimerAlarm(&intimer);
}

void timer_callback(struct timer_alarm_t *alarm, void *arg) {
    *(bool*)arg = true;
}
