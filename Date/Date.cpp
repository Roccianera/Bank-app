#include "Date.h"


const std:: array<unsigned int , 13 > Date::days{
    0,31,28,31,30,31,30,31,31,30,31,30,31};


Date::Date(int d, int m, int y){
    setDate(d,m,y);
}



void Date::setDate(int dd, int mm , int yy){

    if(mm>=1 && mm<=12)
        month= mm;
    else
        throw std::invalid_argument{"Month must be 1-12"};


    if(yy>=1900 && mm<=2100)
        year= yy;
    else
        throw std::invalid_argument{"Year must be  1900 - 2100"};

    if((month==2 && leapYear(year)&& dd>=1 && dd<=29)  ||
        (dd>=1 && dd<=days[month])){
            day=dd;

    }
    else 
        throw std::invalid_argument{" Days out of range"};

    
}

bool Date::leapYear(int testYear){
  return (testYear% 400 ==0 || (testYear%100 != 0 && testYear % 4 ==0));
} 

bool Date::endOfMonth(int testDay) const{
    if(month==2 && leapYear(year))
        return   testDay==29;
    else
        return testDay== days[month];

}

bool Date::operator<(const Date& second) const{
    
    if(this->year< second.year)
        return true;
    
    if(year==second.year && month < second.month)

        return true;

    if(year==second.year && month ==second.month && day< second.day)
        return true;

    
    return false;
}

void Date::helpIncrement()
{
    if(!endOfMonth(day))
        ++day;
    else {
        if(month<12){
            ++month;
            day=1;
        }
        else{
            ++year;
            month=1;
            day=1;
        }

    }
}

Date operator+(const Date& dd,int numdays){
    Date newdate=dd;
    for(int i=1;i<=numdays;i++)
        newdate.helpIncrement();
    return newdate;
}

Date operator+(int numdays,const Date& dd){
    Date newdate=dd;
    for (int  i = 0; i <=numdays; i++)
    {
        newdate.helpIncrement();
    }
    
    return newdate;
}

std::ostream& operator<<(std::ostream& out,const Date& d)
{
    
    static std::string monthName[13]{ "","January","February",
        "March","April","May", "June" , "July", "August",
        "Semptember", "October","November","December"};
    out<<d.day<<" "<<monthName[d.month]<<" "<<d.year;
    return out;
    
}

Date& Date::operator+=(unsigned int additionalDays){

    for (unsigned int i = 0; i < additionalDays; i++)
    {
        helpIncrement();
    }
    
    return *this;
}
// overloard postfix
// dummy integer parameter
Date Date::operator++(int)
{
    Date temp{*this};
    helpIncrement();

    return temp;

}

Date& Date::operator++()
{
    helpIncrement();
    return *this;
    
}