#pragma once
#ifndef STUDENT _H
#define STUDENT _H

#include "resident.h"


class Student : public Resident
{
public:
    //Student();
    Student(int ID, string name, string contact_no, string dept,
        string emergency_no, Location* loc, int _year);

    virtual ~Student();
    void absence_notifier();
    void late_notifier();
    int get_year();
    bool get_on_leave();
    bool get_has_visitor();
    int get_wifi_time_limit();
    int get_late_count();
    void set_year(int y);
    void set_on_leave(bool b);
    void set_has_visitor(bool b);
    void set_wifi_time_limit(int w);
    void increment_late_count();
    void show_info() override;
    static int get_total_student_count;
    static int get_total_student_present;
    static int get_total_student_on_leave;

protected:

private:
    int year;
    bool on_leave;
    bool has_visitor;
    int wifi_time_limit;
    int late_count;
    static int student_count;
    static int student_present;
    static int st_on_leave;
};



#endif // STUDENT _H