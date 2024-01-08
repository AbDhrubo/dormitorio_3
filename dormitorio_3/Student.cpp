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
Student::Student(int ID, string name, string contact_no, string dept, string emergency_no, Location* loc, int _year) :Resident(ID, name, contact_no, dept, emergency_no, loc), year(_year)
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
        cout << "is late" << endl;
    }
    else
    {
        cout << "not late" << endl;
    }
}
int Student::get_year()
{
    return year;
}

bool Student::get_on_leave()
{
    return on_leave;
}

bool Student::get_has_visitor()
{
    return has_visitor;
}

int Student::get_wifi_time_limit()
{
    return wifi_time_limit;
}

int Student::get_late_count()
{
    return late_count;
}

void Student::set_year(int y)
{
    year = y;
}

void Student::set_on_leave(bool b)
{
    on_leave = b;
}

void Student::set_has_visitor(bool b)
{
    has_visitor = b;
}

void Student::set_wifi_time_limit(int w)
{
    wifi_time_limit = w;
}

void Student::increment_late_count()
{
    late_count++;
}

void Student::show_info() {
    cout << "ID: " << get_id() << endl;
    cout << "Name: " << get_name() << endl;
    cout << "Contact no: +88" << get_cont() << endl;
    cout << "Emergency Contact: +88" << get_emergencyno() << endl << "Location: ";
    get_location()->print_Location();
    cout << "Year: " << get_year() << endl;
    cout << "Presence: ";
    if (present) cout << "Yes";
    else cout << "No";
    cout << endl;
    cout << endl;
}
