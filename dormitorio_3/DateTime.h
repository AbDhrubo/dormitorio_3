#pragma once
#include <iostream>
#include <chrono>

using namespace std;

class DateTime {
public:
    DateTime(chrono::system_clock::time_point timePoint) : timePoint_(timePoint) {}

    void printDateTime() const {
        time_t time = chrono::system_clock::to_time_t(timePoint_);
        tm* tmInfo = localtime(&time);

        cout << "Year: " << tmInfo->tm_year + 1900 << endl;
        cout << "Month: " << tmInfo->tm_mon + 1 << endl;
        cout << "Day: " << tmInfo->tm_mday << endl;
        cout << "Hour: " << tmInfo->tm_hour << endl;
        cout << "Minute: " << tmInfo->tm_min << endl;
        cout << "Second: " << tmInfo->tm_sec << endl;
    }

    static int calculateTimeDifferenceInMinutes(const DateTime& startTime, const DateTime& endTime) {
        auto duration = chrono::duration_cast<chrono::minutes>(endTime.timePoint_ - startTime.timePoint_);
        return duration.count();
    }

    static int calculateTimeDifferenceInDays(const DateTime& startTime, const DateTime& endTime) {
        auto duration = chrono::duration_cast<chrono::hours>(endTime.timePoint_ - startTime.timePoint_);
        return duration.count() / 24; // Convert hours to days
    }

private:
    chrono::system_clock::time_point timePoint_;
};