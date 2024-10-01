#include <iostream>
#include "CONT_BANCAR.h"
#include "FUNCTII.cpp"

using namespace std;

int main() {
    CONT_BANCAR* myAccount = new CONT_BANCAR;

    int accountNumber;
    double balance;
    float interestRate;

    cout << "Introdu numarul contului: ";
    cin >> accountNumber;
    myAccount->setAccountNumber(accountNumber);

    cout << "Introdu soldul initial: $";
    cin >> balance;
    myAccount->setBalance(balance);

    cout << "Introdu procentajul dobanzii: ";
    cin >> interestRate;
    interestRate /= 100.0; //Converteste din procentaj in fractie
    myAccount->setInterestRate(interestRate);
    
    cout << "Numarul contului: " << myAccount->getAccountNumber() << endl;
    cout << "Sold: " << myAccount->getBalance() << endl;
    cout << "Dobanda: " << myAccount->getInterestRate() << " %"<< endl;

    double interest = myAccount->calculateInterest();
    cout << "Sold castigat: $" << interest << endl;

    double depositAmount;
    cout << "Introdu suma pe care o depozitezi: $";
    cin >> depositAmount;
    myAccount->deposit(depositAmount);

    double withdrawAmount;
    bool validWithdrawl = false;

    do {
        cout << "Introdu suma pe care o retragi: $";
        cin >> withdrawAmount;

        if (withdrawAmount > myAccount->getBalance()) {
            cout << "Suma depaseste soldul contului. Va rugam incercati din nou" << endl;
        } else if (withdrawAmount <= 0) {
            cout << "Suma introdusa nu este valida. Va rugam incercati din nou" << endl;
        } else {
            validWithdrawl = true; //suma introdusa este valida
            myAccount->withdraw(withdrawAmount);
        }
    } while (!validWithdrawl);

    cout << "Update sold: $" << myAccount->getBalance() << endl;

    delete myAccount;

    return 0;
}