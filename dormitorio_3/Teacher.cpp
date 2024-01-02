#include "Teacher.h"
void Teacher::show_info() 
{
    cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Contact No: +88" << cont_no << endl
        << "Emergency Contact No: +88" << emergency_no << endl
        << "Location: " << endl;
        loc.print_Location();
        cout << "Department: " << dept << endl
        << "Post: " << get_position() << endl
        << "Present: ";

    if (get_presence()) cout << "Yes" << endl << endl;
    else cout << "No" << endl << endl;
}