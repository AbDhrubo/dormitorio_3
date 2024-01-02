#pragma once
#include "Person.h"
#include "Location.h"
#ifndef Resident_H
#define Resident_H

class Resident : public Person
{
public:
    Resident(int _id, string& _name, string& _contact, string& _emerg) : Person(_id, _name, _contact), emergency_no(_emerg) {
        present = 0;
    }
    void presence_updater();
    bool get_presence();
    static void res_count();
    virtual ~Resident();
    string get_emergencyno();
    Location get_location();
    string get_dept();
    void set_location(Location& _loc);
    void set_dept(string& _dept);
    void set_emergencyno(string& number);
    //void show_info() override;



protected:
    bool present;
    static int res;
    string emergency_no;
    string dept;
    Location loc;
};

#endif // Resident_H
