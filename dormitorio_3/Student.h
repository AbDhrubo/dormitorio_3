#pragma once
#ifndef STUDENT _H
#define STUDENT _H

#include "resident.h"


class Student : public Resident
{
public:
    //Student();
    Student(int ID, string name, string contact_no, string dept,
        string emergency_no, Location loc, int _year);

    virtual ~Student();
    void absence_notifier();
    void late_notifier();
    int get_year();
    void set_year(int y);
    void show_info() override;


protected:

private:
    int year;
    static int student_count;
    static int student_present;
    static int st_on_leave;
    bool on_leave;
    bool has_visitor;
    int wifi_time_limit;
    int late_count;
};



#endif // STUDENT _H