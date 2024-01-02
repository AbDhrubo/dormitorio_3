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
    void show_info() 
    {
        cout << "ID: " << get_id() << endl
            << "Name: " << get_name() << endl
            << "Contact No: +88" << get_cont() << endl
            << "Duty Time: " << duty_time / 100 << ":" << duty_time % 100 << endl
            << "Duration: " << duration << " minutes" << endl
            << "Gate No: " << gate_no << endl << endl;
    }
};