#include "DateTime.h"
DateTime::DateTime(const string& timeStringHHMM) {
    int hours, minutes;
    char colon;
    istringstream iss(timeStringHHMM);
    iss >> hours >> colon >> minutes;

    auto currentTime = chrono::system_clock::now();
    auto currentTime_t = chrono::system_clock::to_time_t(currentTime);
    //tm tmInfo = *std::localtime(&currentTime_t);
    tm tmInfo;
    localtime_s(&tmInfo, &currentTime_t);
    tmInfo.tm_hour = hours;
    tmInfo.tm_min = minutes;
    tmInfo.tm_sec = 0;

    timePoint_ = chrono::system_clock::from_time_t(mktime(&tmInfo));
}

void DateTime::printDateTime() const {
    time_t time = chrono::system_clock::to_time_t(timePoint_);
    tm tmInfo;
    localtime_s(&tmInfo, &time);

    cout << "Year: " << tmInfo.tm_year + 1900 << endl;
    cout << "Month: " << tmInfo.tm_mon + 1 << endl;
    cout << "Day: " << tmInfo.tm_mday << endl;
    cout << "Hour: " << tmInfo.tm_hour << endl;
    cout << "Minute: " << tmInfo.tm_min << endl;
    cout << "Second: " << tmInfo.tm_sec << endl;
}

void DateTime::printTime24() const {
    time_t time = chrono::system_clock::to_time_t(timePoint_);
    tm tmInfo; // Create a local tm object
    localtime_s(&tmInfo, &time); // Use localtime_s for safe conversion

    cout << "Time (24-hour format): "
        << setfill('0') << setw(2) << tmInfo.tm_hour << ":" << setw(2) << tmInfo.tm_min
        << setfill(' ') << endl;
}

int DateTime::timeDiffMinute(const DateTime& startTime, const DateTime& endTime) {
    auto duration = chrono::duration_cast<chrono::minutes>(endTime.timePoint_ - startTime.timePoint_);
    return duration.count();
}

int DateTime::timeDiffDay(const DateTime& startTime, const DateTime& endTime) {
    auto duration = chrono::duration_cast<chrono::hours>(endTime.timePoint_ - startTime.timePoint_);
    return duration.count() / 24; // Convert hours to days
}
DateTime DateTime::calcEndTime(const DateTime& startTime, int durationMinutes) {
    auto endTimePoint = startTime.timePoint_ + chrono::minutes(durationMinutes);
    return DateTime(endTimePoint);
}