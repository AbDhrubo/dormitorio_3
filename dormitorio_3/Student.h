#pragma once
#ifndef STUDENT _H
#define STUDENT _H

#include "resident.h"
#include <vector>


class Student : public Resident
{
public:
    //Student();
    Student(int ID, string name, string contact_no, string dept,
        string emergency_no, int loc, int _year);

    virtual ~Student();
    void absence_notifier();
    void late_notifier();
    int get_year();
    bool get_on_leave();
    bool get_has_visitor();
    int get_wifi_time_limit();
    int get_late_count();
    bool get_meet_notification();
    void set_year(int y);
    void set_on_leave(bool b);
    void set_has_visitor(bool b);
    void set_wifi_time_limit(int w);
    void set_late_count(int l);
    void increment_late_count();
    void set_meet_notification(int m);
    void show_student_info(vector <Location>& locco);
    void show_info() override;

    static int get_total_student_count()
    {
        return student_count;
    }
    static void update_total_student_count(int i)
    {
        if (i) student_count++;
        else student_count--;
    }
    static int get_total_student_present()
    {
        return student_present;
    }
    static void update_total_student_present(int i)
    {
        if (i) student_present++;
        else student_present--;
    }
    static int get_total_student_on_leave()
    {
        return student_on_leave;
    }
    static void update_total_student_on_leave(int i)
    {
        if (i) student_on_leave++;
        else student_on_leave--;
    }

protected:

private:
    int year;
    bool on_leave;
    bool has_visitor;
    bool meet_notification;
    int wifi_time_limit;
    int late_count;
    static int student_count;
    static int student_present;
    static int student_on_leave;
};



#endif // STUDENT _H