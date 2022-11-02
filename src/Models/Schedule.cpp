#include "Schedule.h"

using namespace std;

Schedule::Schedule(WeekDay weekday, double startHour, double duration, ScheduleType type, string ucCode, string classCode){
    this -> weekday = weekday;
    this -> startHour = startHour;
    this -> duration = duration;
    this -> type = type;
    this -> ucCode = ucCode;
    this -> classCode = classCode;
}

WeekDay Schedule::getWeekday() {
    return this -> weekday;
}

double Schedule::getStartHour() {
    return this -> startHour;
}

double Schedule::getDuration() {
    return this -> duration;
}

ScheduleType Schedule::getType() {
    return this -> type;
}

string Schedule::getUcCode() {
    return this -> ucCode;
}

string Schedule::getClassCode() {
    return this -> classCode;
}

WeekDay Schedule::weekdayFromString(const string& wday) {
    if (wday == "Monday") return Monday;
    else if (wday == "Tuesday") return Tuesday;
    else if (wday == "Wednesday") return Wednesday;
    else if (wday == "Thursday") return Thursday;
    else return Friday;
}

ScheduleType Schedule::typeFromString(const string& stype) {
    if (stype == "T") return T;
    else if (stype == "TP") return TP;
    else return P;
}

string Schedule::weekDayToString(const WeekDay &weekDay) {
    switch (weekDay) {
        case Monday:
            return "Segunda-Feira";
        case Tuesday:
            return "Terca-Feira";
        case Wednesday:
            return "Quarta-Feira";
        case Thursday:
            return "Quinta-Feira";
        case Friday:
            return "Sexta-Feira";
    }
    return "";
}

string Schedule::typeToString(const ScheduleType &sType) {
    switch (sType) {
        case T:
            return "T";
        case TP:
            return "TP";
        case P:
            return "P";
    }
    return "";
}

void Schedule::sortSchedule(vector<Schedule> &schedule) {
    for (int i = 0; i < schedule.size() - 1; i++) {
        if (schedule[i].getWeekday() > schedule[i + 1].getWeekday()) {
            Schedule temp = schedule[i];
            schedule[i] = schedule[i + 1];
            schedule[i + 1] = temp;
            i = -1;
        }
    }
    for (int i = 0; i < schedule.size()-1; i++) {
        if(schedule[i].getWeekday() == schedule[i+1].getWeekday()){
            if(schedule[i].getStartHour() > schedule[i+1].getStartHour()){
                Schedule temp = schedule[i];
                schedule[i] = schedule[i + 1];
                schedule[i + 1] = temp;
                i = -1;
            }
        }
    }
}


