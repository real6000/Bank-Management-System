#include "Bank.h"
#include <iostream>
#include <algorithm>

void Bank::addAccount() {
    int accNo;
    std::string name;
    double balance;

    std::cout << "Enter Account Number: ";
    std::cin >> accNo;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;

    accounts.emplace_back(accNo, name, balance);
    std::cout << "Account Created Successfully!\n";
}

void Bank::displayAllAccounts() const {
    for (const auto& acc : accounts)
        acc.display();
}

void Bank::searchAccount(int accNo) const {
    auto it = std::find_if(accounts.begin(), accounts.end(),
                           [accNo](const Account& acc) { return acc.getAccountNumber() == accNo; });

    if (it != accounts.end())
        it->display();
    else
        std::cout << "Account not found.\n";
}

void Bank::depositToAccount(int accNo, double amount) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            acc.deposit(amount);
            std::cout << "Deposit Successful.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::withdrawFromAccount(int accNo, double amount) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            if (acc.withdraw(amount))
                std::cout << "Withdrawal Successful.\n";
            else
                std::cout << "Insufficient funds.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::deleteAccount(int accNo) {
    accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
                                  [accNo](const Account& acc) {
                                      return acc.getAccountNumber() == accNo;
                                  }),
                   accounts.end());
    std::cout << "Account Deleted (if it existed).\n";
}

void Bank::modifyAccount(int accNo) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            std::string newName;
            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, newName);
            acc.modify(newName);
            std::cout << "Account Modified.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::loadAccounts() {
    // TODO: Implement file reading logic
}

void Bank::saveAccounts() {
    // TODO: Implement file saving logic
}