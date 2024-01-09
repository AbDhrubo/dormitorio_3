#include "Staff.h"
void Staff::show_time()
{
    DateTime end_time = DateTime::calcEndTime(duty_time_starts, duration);
    duty_time_starts.printTime24();
    cout << " to ";
    end_time.printTime24();
    cout << endl;
    //int hour, min;

    ///*hour = duty_time / 100;
    //min = duty_time % 100;*/
    //if (hour < 10) cout << "0";
    //cout << hour << ":";
    //if (min < 10) cout << "0";
    //cout << min << endl;
}