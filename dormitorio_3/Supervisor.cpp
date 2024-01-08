#include "Supervisor.h"
void Supervisor::show_info() 
{
    cout << "ID: " << id << endl
         << "Name: " << name << endl
         << "Contact No: +88" << cont_no << endl
         << "Duty Time: ";
    show_time();
    cout << "Duration: " << duration << " minutes" << endl
        << "Survey Hour: ";
    show_survey_time();
    cout << endl << endl;
}