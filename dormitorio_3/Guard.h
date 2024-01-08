#pragma once
#include "Staff.h"
class Guard :public Staff
{
private:
    int gate_no;

public:
    Guard(int i, string n, string cn, int t, int d, int g) :Staff(i, n, cn, t, d), gate_no(g) {}

    void set_gate_no(int g)
    {
        gate_no = g;
    }
    int get_gate_no()
    {
        return gate_no;
    }
    void show_info();
   
};