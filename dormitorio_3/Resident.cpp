#include "Resident.h"
#pragma once

int Resident::res = 0;

int Resident::get_location()
{
    return loc;
}

string Resident::get_dept()
{
    return dept;
}

void Resident::set_location(int _loc)
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

void Resident::set_presence(bool b)
{
    present = b;
}


