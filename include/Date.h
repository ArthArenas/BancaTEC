#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

class Date {
    public:
        /// Constructors
        Date();
        Date(int iDay, int iMonth, int iYear, int iHour, int iMinute, int iSecond);

        /// Destructor: The default destructor will do fine

        /// Setters & Getters
        void setDate(int iDay, int iMonth, int iYear);
        void setHour(int iHour, int iMinute, int iSecond);

        int GetiDay();
        int GetiMonth();
        int GetiYear();
        int GetiHour();
        int GetiMinute();
        int GetiSecond();

        string getHourDateFormat(const string sDSeparation = " ", const string sHSeparation = ":");

        /// Operations
        void display();
        void save(ofstream& output);

    private:
        int iDay;
        int iMonth;
        int iYear;
        int iHour;
        int iMinute;
        int iSecond;
        string formatDate(const string sSeparation = " ");
        string formatHour(const string sSeparation = ":");
};

#endif // DATE_H
