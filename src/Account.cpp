#include "Account.h"
#include <iostream>

Account::Account() : accountNumber(0), name(""), balance(0.0) {}

Account::Account(int accNo, const std::string& accName, double initialBalance)
    : accountNumber(accNo), name(accName), balance(initialBalance) {}

void Account::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void Account::display() const {
    std::cout << "Account No: " << accountNumber
              << "\nName: " << name
              << "\nBalance: " << balance << "\n";
}

void Account::modify(const std::string& newName) {
    name = newName;
}

int Account::getAccountNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }
std::string Account::getName() const { return name; }
void Account::setBalance(double newBalance) { balance = newBalance; }