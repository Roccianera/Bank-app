#include <string>
#include<iostream>
#include <chrono>
#include "Date/Date.h"

struct Transaction
{
    Date date;
    std::string typeofTransaction;
    double amount;

    Transaction(std::string type, double amount) : typeofTransaction(type), amount(amount) {

            

            date.setDate();


    }
};
