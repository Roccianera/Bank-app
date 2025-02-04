#include <string>
#include <iostream>
#include <chrono>
#include "Date/Date.h"

struct Transaction
{
    Date date;
    std::string typeofTransaction;
    double amount;

    Transaction(std::string type, double amount) : typeofTransaction(type), amount(amount)
    {

        auto now = std::chrono::system_clock::now();

        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        // Converti in una struttura tm (tempo locale)
        std::tm *localTime = std::localtime(&now_time_t);
//       test
        date.setDate(4, 2, 2025);
    }
};
