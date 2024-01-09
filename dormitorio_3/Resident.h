#pragma once
#include "Person.h"
#include "Location.h"
#ifndef Resident_H
#define Resident_H

class Resident : public Person
{
public:
    Resident(int _id, string& _name, string& _contact, string& _dept, string& _emerg, int _loc) : Person(_id, _name, _contact), dept(_dept), emergency_no(_emerg), loc(_loc) {
        present = 0;
    }
    void presence_updater();
    bool get_presence();
    static void res_count();
    virtual ~Resident();
    string get_emergencyno();
    int get_location();
    string get_dept();
    void set_location(int _loc);
    void set_dept(string& _dept);
    void set_emergencyno(string& number);
    void set_presence(bool b);
    //void show_info() override;



protected:
    bool present;
    static int res;
    string emergency_no;
    string dept;
    int loc;
};

#endif // Resident_H

