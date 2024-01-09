#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <sstream>
#include<iomanip>

using namespace std;

class DateTime {
public:
    DateTime(chrono::system_clock::time_point timePoint) : timePoint_(timePoint) {}
    DateTime() {

    }

    DateTime(const string& timeStringHHMM);

    void printDateTime() const;

    void printTime24() const;


    static int timeDiffMinute(const DateTime& startTime, const DateTime& endTime);

    static int timeDiffDay(const DateTime& startTime, const DateTime& endTime);

    static DateTime calcEndTime(const DateTime& startTime, int durationMinutes);

private:
    chrono::system_clock::time_point timePoint_;
};