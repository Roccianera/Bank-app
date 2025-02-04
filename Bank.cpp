#include "Bank.h"

void Bank::RegisterUser(std::string name, std::string password, double balance)
{   
    //Account number should depend on Bank 

    int max=-1;
    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (users[i].getAccountNumber() > max)
        {
            max = users[i].getAccountNumber();
        }
    }

    int accountNumber = max + 1;



    User newUser(name, password,accountNumber, balance);

    for (size_t i = 0; i < this->users.size(); i++)
    {
        if (users[i].getUsername() == name)
        {
            throw std::invalid_argument("Username already exists");
        }

    }
    
    users.push_back(newUser);

}

void Bank::Deposit( User& user, double amount)
{
    user.deposit(amount);
    

}

void Bank::Withdraw( User& user, double amount)
{
    user.withdraw(amount);
}

void Bank::Transfer( User& user, int accountNumber, double amount)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getAccountNumber() == accountNumber)
        {
            user.withdraw(amount);
            users[i].deposit(amount);
        }
    }
}


void Bank::PrintTransactions(const User& user)
{
    user.printTransactions();
        
    }

void Bank::PrintUserBalance(const User& user)
{
    std::cout << "Balance: " << user.getBalance() << std::endl;
}   

User& Bank::Login(std::string name, std::string password)
{

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == name && users[i].getPassword() == password)
        {
            return users[i];
        }
    }
    throw std::invalid_argument("Invalid username or password");
    

}


