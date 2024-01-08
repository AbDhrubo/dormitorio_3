#include "guard.h"

void Guard::show_info()
{
    cout << "ID: " << get_id() << endl
        << "Name: " << get_name() << endl
        << "Contact No: +88" << get_cont() << endl
        << "Duty Time: ";
    show_time();
    cout << "Duration: " << duration << " minutes" << endl
        << "Gate No: " << gate_no << endl << endl;
}