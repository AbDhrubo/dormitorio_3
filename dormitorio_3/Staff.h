#include "Person.h"
#pragma once
class Staff :public Person
{
protected:
    int duty_time;
    int duration;
    bool on_duty = false;

public:
    Staff(int i, string n, string cn, int t, int d) :Person(i, n, cn), duty_time(t), duration(d) {}

    void set_duty_time(int t)
    {
        duty_time = t;
    }
    void set_duration(int d)
    {
        duration = d;
    }
    void set_on_duty(bool b)
    {
        on_duty = b;
    }
    int get_duty_time()
    {
        return duty_time;
    }
    int get_duration()
    {
        return duration;
    }
    bool get_on_duty()
    {
        return on_duty;
    }
};