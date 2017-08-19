#include "Date.h"
#include <ctime>
#include <fstream>

/// Constructors
/*
Date

This is the constructor without arguments

Parameters:
    void
Returns:
    It's a constructor
*/
Date::Date() {
    time_t tSeconds = time(0); // Stores the amount of seconds from 01/01/1900
    tm* tmRightNow = localtime(&tSeconds);
    iYear = int(1900 + tmRightNow -> tm_year);
    iMonth = int(1 + tmRightNow -> tm_mon);
    iDay = int(tmRightNow -> tm_mday);
    iHour = int(tmRightNow -> tm_hour);
    iMinute = int(tmRightNow -> tm_min);
    iSecond = int(tmRightNow -> tm_sec);
}
/*
Date

This is the constructor with arguments

Parameters:
    int iDay    Stores the days
    int iMonth  Stores the months
    int iYear   Stores the years
    int iHour   Stores the hours
    int iMinute Stores the minutes
    int iSecond Stores the seconds
Returns:
    It's a constructor
*/
Date::Date(int iDay, int iMonth, int iYear, int iHour, int iMinute, int iSecond) {
    this -> iDay = iDay;
    this -> iMonth = iMonth;
    this -> iYear = iYear;
    this -> iHour = iHour;
    this -> iMinute = iMinute;
    this -> iSecond = iSecond;
}
/// Setters & Getters
/*
setDate

This is the setter for the day, month and year

Parameters:
    int iDay    Stores the days
    int iMonth  Stores the months
    int iYear   Stores the years
Returns:
    void
*/
void Date::setDate(int iDay, int iMonth, int iYear) {
    this -> iDay = iDay;
    this -> iMonth = iMonth;
    this -> iYear = iYear;
}
/*
setHour

This is the setter for the hour, minute, second

Parameters:
    int iHour   Stores the hours
    int iMinute Stores the minutes
    int iSecond Stores the seconds
Returns:
    void
*/
void Date::setHour(int iHour, int iMinute, int iSecond) {
    this -> iHour = iHour;
    this -> iMinute = iMinute;
    this -> iSecond = iSecond;
}
/*
GetiDay

This is the getter for the date

Parameters:
    void
Returns:
    int iDay    Stores the days
*/
int Date::GetiDay() {
    return iDay;
}
/*
GetiMonth

This is the getter for the month

Parameters:
    void
Returns:
    int iMonth  Stores the months
*/
int Date::GetiMonth() {
    return iMonth;
}
/*
GetiYear

This is the getter for the year

Parameters:
    void
Returns:
    int iYear   Stores the years
*/
int Date::GetiYear() {
    return iYear;
}
/*
GetiHour

This is the getter for the hour

Parameters:
    void
Returns:
    int iHour   Stores the hours
*/
int Date::GetiHour() {
    return iHour;
}
/*
GetiMinute

This is the getter for the minute

Parameters:
    void
Returns:
    int iMinute Stores the minutes
*/
int Date::GetiMinute() {
    return iMinute;
}
/*
GetiSecond

This is the getter for the seconds

Parameters:
    void
Returns:
    int iSecond Stores the seconds
*/
int Date::GetiSecond() {
    return iSecond;
}
/*
getHourDateFormat

Concatenates the date and hour in a single string with a determined format

Parameters:
    const string sDSeparation   Stores the format for the date
    const string sHSeparation   Stores the format for the hour
Returns:
    string sDate                Stores the resulting date in the given format
*/
string Date::getHourDateFormat(const string sDSeparation, const string sHSeparation) {
    string sDate;
    sDate = formatDate(sDSeparation) + sDSeparation + formatHour(sHSeparation);
    return sDate;
}

/// Operations
/*
display

Displays the date

Parameters:
    void
Returns:
    void
*/
void Date::display() {
    cout << formatDate() << " " << formatHour();
}
/*
save

Saves the date in an output format

Parameters:
    ofstream& output    Stores the ofstream that outputs information
Returns:
    void
*/
void Date::save(ofstream& output) {
    output << formatDate() << " " << formatHour();
}

/// Private methods
/*
formatDate

Converts the integer information into strings and concatenates them to
form a date with a given format

Parameters:
    const string sSeparation    Stores the format for the date
Returns:
    string sResult              Stores the resulting date format
*/
string Date::formatDate(const string sSeparation) {
    // Define variables and arrays to be used
    string sResult;
    string aMonths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Add month to the string
    sResult += aMonths[iMonth - 1];
    sResult += sSeparation;
    // Add day to the string
    if(iDay >= 10){
        sResult += char(iDay / 10 + 48);
        sResult += char(iDay % 10 + 48);
    }
    else{
        sResult += char(iDay + 48);
    }
    sResult += sSeparation;
    // Add year to the string
    int iTemp = iYear;
    sResult += char(iTemp / 1000 + 48);
    iTemp %= 1000;
    sResult += char(iTemp / 100 + 48);
    iTemp %= 100;
    sResult += char(iTemp / 10 + 48);
    iTemp %= 10;
    sResult += char(iTemp + 48);
    // Return result
    return sResult;
}
/*
formatHour

Converts the integer information into strings and concatenates them to
form an hour with a given format

Parameters:
    const string sSeparation    Stores the format for the hour
Returns:
    string sResult              Stores the resulting hour format
*/
string Date::formatHour(const string sSeparation) {
    // Define variables to be used
    string sResult;
    // Add hour into the string
    if(iHour >= 10){
        sResult += char(iHour / 10 + 48);
        sResult += char(iHour % 10 + 48);
    }
    else{
        sResult += '0';
        sResult += char(iHour + 48);
    }
    sResult += sSeparation;
    // Add minute into the string
    if(iMinute >= 10){
        sResult += char(iMinute / 10 + 48);
        sResult += char(iMinute % 10 + 48);
    }
    else{
        sResult += '0';
        sResult += char(iMinute + 48);
    }
    sResult += sSeparation;
    // Add second into the string
    if(iSecond >= 10){
        sResult += char(iSecond / 10 + 48);
        sResult += char(iSecond % 10 + 48);
    }
    else{
        sResult += '0';
        sResult += char(iSecond + 48);
    }
    // Return result
    return sResult;
}
