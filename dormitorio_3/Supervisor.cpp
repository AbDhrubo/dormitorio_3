#include "Supervisor.h"
void Supervisor::show_info() 
{
    cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Contact No: +88" << cont_no << endl
        << "Duty Time: " << duty_time / 100 << ":" << duty_time % 100 << endl
        << "Duration: " << duration << " minutes" << endl
        << "Survey Hour: " << surv_hour / 100 << ":" << surv_hour % 100 << endl << endl;
}