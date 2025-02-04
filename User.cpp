#include "User.h"

User::User(std::string username, std::string password, int accountNumber, double balance)
{
    this->username = username;
    this->password = password;
    this->accountNumber = accountNumber;
    this->balance = balance;
}

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}

void User::setUsername(std::string username)
{
    this->username = username;
}

void User::setPassword(std::string password)
{
    this->password = password;
}

int User::getAccountNumber() const
{
    return accountNumber;
}

void User::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}

double User::getBalance() const
{
    return balance;
}

void User::setBalance(double balance)
{
    this->balance = balance;
}

void User::deposit(double amount)
{
    balance += amount;

    this->transactions.push_back(Transaction("Deposit", amount));
}

void User::withdraw(double amount)
{
    balance -= amount;
    this->transactions.push_back(Transaction("Withdraw", amount));
}

void User::printTransactions() const
{
    for (int i = 0; i < transactions.size(); i++)
    {
        std::cout << "Transaction type: " << transactions[i].typeofTransaction << std::endl;
        std::cout << "Amount: " << transactions[i].amount << std::endl;
        std::cout << "Date: " << transactions[i].date << std::endl;
    }
}