#include "Student.h"
int Student::student_count = 0;
int Student::student_present = 0;
int Student::student_on_leave = 0;

Student::Student(int ID, string name, string contact_no, string dept, string emergency_no, Location* loc, int _year) :Resident(ID, name, contact_no, dept, emergency_no, loc), year(_year)
{
    on_leave = false;
    has_visitor = false;
    wifi_time_limit = 12000;
    meet_notification = false;
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

bool Student::get_meet_notification()
{
    return meet_notification;
}

void Student::set_year(int y)
{
    year = y;
}

void Student::set_on_leave(bool b)
{
    on_leave = b;
    if (b)
    {
        present = false;
        update_total_student_present(0);
        update_total_student_on_leave(1);
    }
    else
    {
        present = true;
        update_total_student_present(1);
        update_total_student_on_leave(0);
    }
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
    if (late_count >= 3) meet_notification = true;
}

void Student::set_meet_notification(int m)
{
    if (m) meet_notification = true;
    else meet_notification = false;
}

void Student::show_info() {
    cout << "ID: " << get_id() << endl;
    cout << "Name: " << get_name() << endl;
    cout << "Year: " << get_year() << endl;
    cout << "Department: " << get_dept() << endl;
    cout << "Contact No: +88" << get_cont() << endl;
    cout << "Emergency Contact No: +88" << get_emergencyno() << endl << "Location: ";
    get_location()->print_Location();
    cout << "Presence: ";
    if (present) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << "On Leave: ";
    if (on_leave) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << "Has A Visitor: ";
    if (has_visitor) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << "Call From Supervisor: ";
    if (meet_notification) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << "Late: " << late_count << " times" << endl << endl;
}

