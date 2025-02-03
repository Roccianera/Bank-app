#ifndef DATE_H
#define DATE_H
#include <array>
#include <iostream>


class Date
{

public:
    Date(int d= 1, int m=1, int y =1900);
    void setDate(int , int , int );
    Date& operator++();
    Date operator++(int);
    Date& operator+=(unsigned int );
    static bool leapYear(int);
    bool endOfMonth(int )const;
    bool operator<(const Date&) const;
    friend std::ostream& operator<<(std::ostream&,const Date&);
    friend Date operator+(int,const Date&);
    friend Date operator+(const Date&,int);
    
private:
    unsigned int day, month , year;
    static const std::array<unsigned int,13> days;
    void helpIncrement();

};

#endif