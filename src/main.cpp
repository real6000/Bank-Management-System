#include "Bank.h"
#include <iostream>

int main() {
    Bank bank;
    bank.loadAccounts();  // not implemented yet

    int choice;
    do {
        std::cout << "\n--- Bank Menu ---\n"
                  << "1. Add Account\n"
                  << "2. Display All Accounts\n"
                  << "3. Search Account\n"
                  << "4. Deposit\n"
                  << "5. Withdraw\n"
                  << "6. Modify Account\n"
                  << "7. Delete Account\n"
                  << "8. Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        int accNo;
        double amount;

        switch (choice) {
            case 1:
                bank.addAccount();
                break;
            case 2:
                bank.displayAllAccounts();
                break;
            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                bank.searchAccount(accNo);
                break;
            case 4:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                std::cout << "Enter Deposit Amount: ";
                std::cin >> amount;
                bank.depositToAccount(accNo, amount);
                break;
            case 5:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                std::cout << "Enter Withdrawal Amount: ";
                std::cin >> amount;
                bank.withdrawFromAccount(accNo, amount);
                break;
            case 6:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                bank.modifyAccount(accNo);
                break;
            case 7:
                std::cout << "Enter Account Number: ";
                std::cin >> accNo;
                bank.deleteAccount(accNo);
                break;
            case 8:
                bank.saveAccounts();  // not implemented yet
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option.\n";
        }

    } while (choice != 8);

    return 0;
}