#pragma once
#include "Staff.h"

enum class Position { Head, Assistant, Junior };
enum class Meal { Breakfast, Lunch, Dinner };

class Cook :public Staff
{
private:
    Position position;
    Meal meal;

public:
    Cook(int i, string n, string cn, int t, int d, Position p, Meal m) :Staff(i, n, cn, t, d), position(p), meal(m) {}

    void set_position(Position p)
    {
        position = p;
    }
    void set_meal(Meal m)
    {
        meal = m;
    }
    string get_position();
    string get_meal();
    void show_info() override;
};