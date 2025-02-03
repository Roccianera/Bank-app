#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Transaction.h"
class User
{
private:
    std::string username;
    std::string password;
    int accountNumber;
    double balance;
    std::vector<Transaction> transactions;

public:
    User(std::string, std::string, int, double = 0.0);
    std::string getUsername() const;
    std::string getPassword() const;
    void setUsername(std::string);
    void setPassword(std::string);
    int getAccountNumber() const;
    void setAccountNumber(int);
    double getBalance() const;
    void setBalance(double);
    void deposit(double);
    void withdraw(double);
    

}
;

#endif