#pragma once
#include "Person.h"
#include "Location.h"
#include "DateTime.h"
#ifndef Resident_H
#define Resident_H

class Resident : public Person
{
public:
    Resident(int _id, string& _name, string& _contact, string& _dept, string& _emerg, Location* _loc) : Person(_id, _name, _contact), dept(_dept), emergency_no(_emerg), loc(_loc) {
        present = 0;
    }
    void presence_updater();
    bool get_presence();
    static void res_count();
    virtual ~Resident();
    string get_emergencyno();
    Location* get_location();
    string get_dept();
    void set_location(Location* _loc);
    void set_dept(string& _dept);
    void set_emergencyno(string& number);
    void start_leave(int dur);
    void end_leave();
    //void show_info() override;



protected:
    bool present;
    static int res;
    string emergency_no;
    string dept;
    Location *loc;
    DateTime leave_started;
    int leave_duration;
    int leave_count;
    bool on_leave;
};

#endif // Resident_H

