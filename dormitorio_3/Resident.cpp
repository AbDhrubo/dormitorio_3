#include "Resident.h"
#pragma once

int Resident::res = 0;

//Resident::Resident(string _id, string& _name, string contact, string emerg)
//{
//
//}

Location* Resident::get_location()
{
    return loc;
}

string Resident::get_dept()
{
    return dept;
}

void Resident::set_location(Location* _loc)
{
    loc = _loc;
}

void Resident::set_dept(string& _dept)
{
    dept = _dept;
}


void Resident::set_emergencyno(string& number)
{
    emergency_no = number;
}


Resident::~Resident()
{
    //dtor
}
void Resident::presence_updater()
{
    present = present ^ 1;
}

//Resident::Resident(string _name, int id, string contact, string _dept, string emerg, string loc) :Person(name, ID, Contact_no), dept(_dept), emergency_no(emerg), location(loc)
//{
//
//}

string Resident::get_emergencyno()
{
    return emergency_no;
}

void Resident::res_count()
{
    res++;
}

bool Resident::get_presence() {
    return present;
}

void Resident::start_leave(int dur) {
    try {
        if (on_leave) throw 1;
        DateTime temp(chrono::system_clock::now());
        leave_started = temp;
        on_leave = 1;
        leave_duration = dur;
        cout << "Congratulations. You are on leave for " << dur << " days." << endl;
    }
    catch (int n) {
        cout << "You are already on leave." << endl;
    }
}

void Resident::end_leave() {
    try {
        if (!present) throw 1;
        DateTime temp(chrono::system_clock::now());
        if (DateTime::timeDiffDay(leave_started, temp) > leave_duration) {
            cout << "Supervisor dakse" << endl;
        }
        on_leave = 0;
    }
    catch (int n) {
        cout << "You need to be present in order to perform this action." << endl;
    }
}


