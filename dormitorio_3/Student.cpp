#include "Student.h"

Student::Student()
{
    on_leave = false;
    has_visitor = false;
    wifi_time_limit = 12000;
    late_count = 0;
}
Student::Student(string name, int ID, string contact_no, string dept, string emergency_no, string loc, int _year) :resident(name, ID, contact_no, dept, emergency_no, location), year(_year)
{
    on_leave = false;
    has_visitor = false;
    wifi_time_limit = 12000;
    late_count = 0;
}

Student::~Student()
{
    //dtor
}
void Student::absence_notifier()
{
    if (on_leave)
    {
        cout << "Absent" << endl;
    }
    else {
        cout << "present" << endl;
    }
}

void Student::late_notifier()
{
    if (late_count)
    {
        cout << "Is late" << endl;
    }
    else
    {
        cout << not_late << endl;
    }
}
int Student::get_year()
{
    return year;
}

void Student::set_year(int y)
{
    year = y;
}

void Student::show_info() {
    cout << "ID: " << get_id() << endl;
    cout << "Name: " << get_name() << endl;
    cout << "Contact no: " << get_cont() << endl;
}
