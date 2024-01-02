#pragma once
#ifndef STUDENT _H
#define STUDENT _H

#include "resident.h"


class Student : public resident
{
public:
    Student();
    Student(string name, int ID, string contact_no, string dept,
        string emergency_no, string loc, int _year);

    virtual ~Student();
    void absence_notifier();
    void late_notifier();
    int get_year();
    void set_year(int y);
    void show_info() override;


protected:

private:
    int year;
    bool on_leave;
    bool has_visitor;
    int wifi_time_limit;
    int late_count;
};

#endif // STUDENT _H