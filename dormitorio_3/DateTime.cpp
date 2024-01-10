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

string DateTime::getDate() const {
    time_t time = chrono::system_clock::to_time_t(timePoint_);
    tm* tmInfo = gmtime(&time);

    if (tmInfo != nullptr) {
        ostringstream oss;
        oss << setfill('0') << setw(4) << tmInfo->tm_year + 1900
            << setw(2) << tmInfo->tm_mon + 1
            << setw(2) << tmInfo->tm_mday;
        return oss.str();
    }
    else {
        cerr << "Error getting date." << endl;
        return "";
    }
}

bool DateTime::areDatesDifferent(const DateTime& other) const {
    time_t time1 = chrono::system_clock::to_time_t(timePoint_);
    time_t time2 = chrono::system_clock::to_time_t(other.timePoint_);

    tm* tmInfo1 = gmtime(&time1);
    tm* tmInfo2 = gmtime(&time2);

    if (tmInfo1 != nullptr && tmInfo2 != nullptr) {
        return tmInfo1->tm_year != tmInfo2->tm_year ||
            tmInfo1->tm_mon != tmInfo2->tm_mon ||
            tmInfo1->tm_mday != tmInfo2->tm_mday;
    }
    else {
        cerr << "Error comparing dates." << endl;
        return false; // Assuming an error means the dates are not considered different
    }
}

bool DateTime::isMidnight() const {
    time_t time = chrono::system_clock::to_time_t(timePoint_);
    tm* tmInfo = gmtime(&time);

    if (tmInfo != nullptr) {
        int hour = tmInfo->tm_hour;
        return hour >= 0 && hour < 6;
    }
    else {
        cerr << "Error checking time range." << endl;
        return false;
    }
}

bool DateTime::isVisiting_hour() const {
    time_t time = chrono::system_clock::to_time_t(timePoint_);
    tm* tmInfo = gmtime(&time);

    if (tmInfo != nullptr) {
        int hour = tmInfo->tm_hour;
        return hour >= 8 && hour < 22;
    }
    else {
        cerr << "Error checking time range." << endl;
        return false;
    }
}

bool DateTime::areMonthsDifferent(const DateTime& other) const {
    time_t time1 = chrono::system_clock::to_time_t(timePoint_);
    time_t time2 = chrono::system_clock::to_time_t(other.timePoint_);

    tm* tmInfo1 = gmtime(&time1);
    tm* tmInfo2 = gmtime(&time2);

    if (tmInfo1 != nullptr && tmInfo2 != nullptr) {
        return tmInfo1->tm_year != tmInfo2->tm_year ||
            tmInfo1->tm_mon != tmInfo2->tm_mon;
    }
    else {
        cerr << "Error comparing dates." << endl;
        return false; // Assuming an error means the dates are not considered different
    }
}

void DateTime::updateDate(const DateTime& other) {
    // Extract date components from the passed DateTime object
    std::time_t otherTime = std::chrono::system_clock::to_time_t(other.timePoint_);
    std::tm* otherTmInfo = std::gmtime(&otherTime);

    if (otherTmInfo != nullptr) {
        // Extract the current time components
        std::time_t currentTime = std::chrono::system_clock::to_time_t(timePoint_);
        std::tm* currentTmInfo = std::gmtime(&currentTime);

        if (currentTmInfo != nullptr) {
            // Update the date components of the current time with those from the passed object
            currentTmInfo->tm_year = otherTmInfo->tm_year;
            currentTmInfo->tm_mon = otherTmInfo->tm_mon;
            currentTmInfo->tm_mday = otherTmInfo->tm_mday;

            // Convert the modified tm structure back to a time_point
            timePoint_ = std::chrono::system_clock::from_time_t(std::mktime(currentTmInfo));
        }
        else {
            std::cerr << "Error updating date." << std::endl;
        }
    }
    else {
        std::cerr << "Error updating date." << std::endl;
    }
}