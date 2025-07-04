#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    Account();
    Account(int accNo, const std::string& accName, double initialBalance);

    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    void modify(const std::string& newName);

    int getAccountNumber() const;
    double getBalance() const;
    std::string getName() const;

    void setBalance(double newBalance);
};

#endif