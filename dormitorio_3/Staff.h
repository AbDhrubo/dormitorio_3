#include "Person.h"
#pragma once
class Staff :public Person
{
protected:
    int duty_time;
    int duration;
    bool on_duty = false;
    bool hall_presence = false;

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
    void presence_updater()
    {
        if (hall_presence) hall_presence = false;
        else hall_presence = true;
    }

    void show_time()
    {
        int hour, min;
        hour = duty_time / 100;
        min = duty_time % 100;
        if (hour < 10) cout << "0";
        cout << hour << ":";
        if (min < 10) cout << "0";
        cout << min << endl;
    }
};