
#ifndef BANK_H
#define BANK_H
#include <string>
#include <vector>
#include "User.h"

class Bank
{
    private:
    std::vector<User> users;
    public:
    Bank();
    void RegisterUser(std::string name, std::string password, double balance);
    void Deposit( User& user, double amount);
    void Withdraw( User& user, double amount);
    void Transfer( User& user, int accountNumber, double amount);
    void PrintTransactions(const User& user);
    void PrintUserBalance(const User& user);
    User& Login(std::string name, std::string password);

};

#endif
