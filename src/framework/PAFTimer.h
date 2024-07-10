//
// Created by Alessandro Mascolo on 28/06/24.
//

#ifndef PS2APP_PAFTIMER_H
#define PS2APP_PAFTIMER_H

#include <kernel.h>
#include <timer.h>
#include <timer_alarm.h>


class Timer {
public:
    explicit Timer(int time);
    void Retime(int newTime);
    bool Check() const;
    void Start();
    void Stop();
private:
    struct timer_alarm_t intimer{};
    bool flag = false;

};

#endif //PS2APP_PAFTIMER_H
