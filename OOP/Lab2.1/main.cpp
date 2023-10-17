#include <iostream>
#include "CONT_BANCAR.h"
#include "FUNCTII.cpp"

int main() {
    CONT_BANCAR* myAccount = new CONT_BANCAR;

    int accountNumber;
    double balance;
    float interestRate;

    std::cout << "Introdu numarul contului: ";
    std::cin >> accountNumber;
    myAccount->setAccountNumber(accountNumber);

    std::cout << "Introdu soldul initial: $";
    std::cin >> balance;
    myAccount->setBalance(balance);

    std::cout << "Introdu procentajul dobanzii: ";
    std::cin >> interestRate;
    interestRate /= 100.0; //Converteste din procentaj in fractie
    myAccount->setInterestRate(interestRate);
    
    std::cout << "Numarul contului: " << myAccount->getAccountNumber() << std::endl;
    std::cout << "Sold: " << myAccount->getBalance() << std::endl;
    std::cout << "Dobanda: " << myAccount->getInterestRate() << " %"<< std::endl;

    double interest = myAccount->calculateInterest();
    std::cout << "Sold castigat: $" << interest << std::endl;

    double depositAmount;
    std::cout << "Introdu suma pe care o depozitezi: $";
    std::cin >> depositAmount;
    myAccount->deposit(depositAmount);

    double withdrawAmount;
    bool validWithdrawl = false;

    do {
        std::cout << "Introdu suma pe care o retragi: $";
        std::cin >> withdrawAmount;

        if (withdrawAmount > myAccount->getBalance()) {
            std::cout << "Suma depaseste soldul contului. Va rugam incercati din nou" << std::endl;
        } else if (withdrawAmount <= 0) {
            std::cout << "Suma introdusa nu este valida. Va rugam incercati din nou" << std::endl;
        } else {
            validWithdrawl = true; //suma introdusa este valida
            myAccount->withdraw(withdrawAmount);
        }
    } while (!validWithdrawl);

    std::cout << "Update sold: $" << myAccount->getBalance() << std::endl;

    delete myAccount;

    return 0;
}