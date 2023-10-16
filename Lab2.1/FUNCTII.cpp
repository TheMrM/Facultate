// FUNCTII.cpp
#include "CONT_BANCAR.h"

void CONT_BANCAR::setAccountNumber(int accountNum) {
    NUMARCONT = accountNum;
}

void CONT_BANCAR::setBalance(double balance) {
    SOLD = balance;
}

void CONT_BANCAR::setInterestRate(float rata) {
    RATADOBANZII = rata;
}

int CONT_BANCAR::getAccountNumber() {
    return NUMARCONT;
}

double CONT_BANCAR::getBalance() {
    return SOLD;
}

float CONT_BANCAR::getInterestRate() {
    return RATADOBANZII;
}

double CONT_BANCAR::calculateInterest() {
    return SOLD * RATADOBANZII;
}

void CONT_BANCAR::deposit(double amount) {
    if (amount > 0) {
        SOLD += amount;
    }
}

void CONT_BANCAR::withdraw(double amount) {
    if (amount > 0 && amount <= SOLD) {
        SOLD -= amount;
    } else {
        std::cout << "Suma nu poate fi retrasa. Va rugam verificati suma si incercati din nou." << std::endl;
    }
}