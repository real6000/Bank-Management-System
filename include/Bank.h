#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

class Bank {
private:
    std::vector<Account> accounts;

public:
    void loadAccounts();   // TODO: file I/O
    void saveAccounts();   // TODO: file I/O

    void addAccount();
    void displayAllAccounts() const;
    void searchAccount(int accNo) const;
    void depositToAccount(int accNo, double amount);
    void withdrawFromAccount(int accNo, double amount);
    void deleteAccount(int accNo);
    void modifyAccount(int accNo);
};

#endif