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
};
