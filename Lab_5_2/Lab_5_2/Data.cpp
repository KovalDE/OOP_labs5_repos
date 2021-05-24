#include "Data.h"

void Data::SetDay(int value)
{ 
    s.day = value;
}

void Data::SetMonth(int value)
{ 
    s.month = value;
}

void Data::SetYear(int value)
{ 
    s.year = value;
}
int Data::NameOfDay()
{
    int d = s.day;
    int month = s.month;
    int year = s.year;
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int i = (d + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return i;
}
bool Data::check(int day1, int month1, int year1)
{
    if (month1 < 13 && month1>0)
    {
        if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12)
        {
            if (day1 < 32 && day1 > 0) return 1;
            else throw Error("Count of days are not correct bro!");
        }
        else if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)
        {
            if (day1 < 31 && day1 > 0) return 1;
            else throw Error("Count of days are not correct bro!");
        }
        else if (month1 == 2)
        {
            if (year1 % 4 == 0)
            {
                if (day1 < 30 && day1 > 0) return 1;
                else throw Error("Count of days are not correct bro!");
            }
            else if (day1 < 29 && day1 > 0) return 1;
            else throw Error("Count of days are not correct bro!");
        }

    }
    else throw Error("Month are not correct bro!");
}
ostream& operator << (ostream& out, Data& a)
{
    int res = a.NameOfDay();
    string b[7] = { "Monday","Tuesday","Wednessdat","Thursday","Friday","Saturday","Sunday" };
    out <<"It is - "<< b[res-1]<< endl;
    return out;
}

istream& operator >> (istream& in, Data& a)
{
    cout << "Input date:" << endl;
    int day1, month1, year1;
    cout << "Day   = "; in >> day1;
    cout << "Month = ";in >> month1;
    cout << "Year  = ";in >> year1;
    if(a.check(day1,month1,year1)==1)
    a.SetDay(day1),a.SetMonth(month1),a.SetYear(year1);

    return in;
};