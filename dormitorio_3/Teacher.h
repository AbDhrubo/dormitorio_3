#pragma once
#include "Resident.h"

enum class T_Position { Lecturer, Assistant_Professor, Associate_Professor, Professor };

class Teacher :public Resident
{
private:
    T_Position position;

public:
    Teacher(int i, string n, string cn, string em_cn, string _dept, int loc, T_Position p) :Resident(i, n, cn, em_cn, _dept, loc), position(p) {}

    void set_position(T_Position p)
    {
        position = p;
    }
    string get_position()
    {
        if (position == T_Position::Assistant_Professor)
            return string("Assistant Professor");
        else if (position == T_Position::Associate_Professor)
            return string("Associate Professor");
        else if (position == T_Position::Lecturer)
            return string("Lecturer");
        else if (position == T_Position::Professor)
            return string("Professor");
    }
    void show_info() override;
};