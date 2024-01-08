#pragma once
#include "Staff.h"

class Supervisor :public Staff
{
private:
    int surv_hour;

public:
    Supervisor(int i, string n, string cn, int t, int d, int h) :Staff(i, n, cn, t, d), surv_hour(h) {}

    void set_surv_hour(int h)
    {
        surv_hour = h;
    }
    int get_surv_hour()
    {
        return surv_hour;
    }
    void show_info() override;
    void show_survey_time()
    {
        int hour, min;
        hour = surv_hour / 100;
        min = surv_hour % 100;
        if (hour < 10) cout << "0";
        cout << hour << ":";
        if (min < 10) cout << "0";
        cout << min << endl;
    }
};
