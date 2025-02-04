#include <iostream>
using namespace std;
#include "Bank.h"
#include "User.h"

void showMenu(bool isLoggedIn)
{
    cout << "======================" << endl;
    if (!isLoggedIn)
    {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
    }
    else
    {
        cout << "3. Check Balance" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Deposit" << endl;
        cout << "6. Logout" << endl;
        cout << "7. PrintTransactions" << endl;
    }
    cout << "8. Exit" << endl;
    cout << "======================" << endl;
}

int main()
{
    int choice;
    bool isLoggedIn = false;
    User *user = nullptr;
    Bank bank = Bank();

    do
    {
        showMenu(isLoggedIn);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!isLoggedIn)
            {
                cout << "Register selected" << endl;
                std::string email;
                std::string password;
                double balance;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter balance: ";
                cin >> balance;
                bank.RegisterUser(email, password, balance);
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        case 2:
            if (!isLoggedIn)
            {
                cout << "Login selected" << endl;
                std::string email;
                std::string password;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                try
                {
                    user = &bank.Login(email, password);
                    isLoggedIn = true;
                }
                catch (const std::invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
            break;
        case 3:
            if (isLoggedIn)
            {
                cout << "Check Balance selected" << endl;
                cout << "Your current balance is: " << user->getBalance() << endl;
            }
            else
            {
                cout << "You need to log in first." << endl;
            }
            break;
        case 4:
            if (isLoggedIn)
            {
                cout << "Withdraw selected" << endl;
                cout << "Enter amount to withdraw: ";
                double amount;
                cin >> amount;

                bank.Withdraw(*user, amount);
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        case 5:
            if (isLoggedIn)
            {
                cout << "Deposit selected" << endl;
                cout << "Enter amount to deposit: ";
                double amount;
                cin >> amount;
                bank.Deposit(*user, amount);
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        case 6:
            if (isLoggedIn)
            {
                cout << "Logout selected" << endl;
                isLoggedIn = false;
                user = nullptr;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        case 7:
            if (isLoggedIn)
            {
                cout << "Print transction selected" << endl;
                bank.PrintTransactions(*user);
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}