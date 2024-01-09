#include "Person.h"
#include "DateTime.h"
#pragma once
class Staff :public Person
{
protected:
    DateTime duty_time_starts;
    int duration;
    bool on_duty = false;
    bool hall_presence = false;

public:
    Staff(int i, string n, string cn, string t, int d) :Person(i, n, cn), duty_time_starts(t), duration(d) {}

    void set_duty_time(string in)
    {
        duty_time_starts = in;
    }
    void set_duration(int d)
    {
        duration = d;
    }
    void set_on_duty(bool b)
    {
        on_duty = b;
    }
    DateTime get_duty_time()
    {
        return duty_time_starts;
    }
    int get_duration()
    {
        return duration;
    }
    bool get_on_duty()
    {
        return on_duty;
    }
    void presence_updater()
    {
        if (hall_presence) hall_presence = false;
        else hall_presence = true;
    }

    void show_time();
};