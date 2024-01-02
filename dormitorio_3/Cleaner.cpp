#include "Cleaner.h"

void Cleaner::show_info() 
{
    cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Contact No: +88" << cont_no << endl
        << "Duty Time: " << duty_time / 100 << ":" << duty_time % 100 << endl
        << "Duration: " << duration << " minutes" << endl
        << "Location: Block " << get_block() << " ,Floor " << floor << endl
        << "Status: " << completed << " rooms cleaned out of " << target << " rooms" << endl << endl;
}