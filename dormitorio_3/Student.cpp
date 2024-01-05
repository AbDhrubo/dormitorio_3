#include "Student.h"
int Student::student_count = 0;
int Student::student_present = 0;
int Student::st_on_leave = 0;
/*Student::Student()
{
    on_leave = false;
    has_visitor = false;
    wifi_time_limit = 12000;
    late_count = 0;
}*/
Student::Student(int ID, string name, string contact_no, string dept, string emergency_no, Location loc, int _year) :Resident(ID, name, contact_no, dept, emergency_no, loc), year(_year)
{
    on_leave = false;
    has_visitor = false;
    wifi_time_limit = 12000;
    late_count = 0;
    student_count++;
    student_present++;
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
        cout << "not_late" << endl;
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
