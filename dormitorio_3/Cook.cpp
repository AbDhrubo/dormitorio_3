#include "Cook.h"
string Cook::get_position()
{
    if (position == Position::Head)
        return string("Head");
    else if (position == Position::Assistant)
        return string("Assistant");
    else if (position == Position::Junior)
        return string("Junior");
}

string Cook::get_meal()
{
    if (meal == Meal::Breakfast)
        return string("Breakfast");
    else if (meal == Meal::Dinner)
        return string("Dinner");
    else if (meal == Meal::Lunch)
        return string("Lunch");
}

void Cook::show_info() 
{
    cout << "ID: " << id << endl
        << "Name: " << name << endl
        << "Contact No: +88" << cont_no << endl
        << "Duty Time: ";
        show_time();
        cout << "Duration: " << duration << " minutes" << endl
        << "Position: " << get_position() << " Cook" << endl
        << "Meal: " << get_meal() << endl << endl;
}