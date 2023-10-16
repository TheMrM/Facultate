// CONT_BANCAR.h
#ifndef CONT_BANCAR_H
#define CONT_BANCAR_H

class CONT_BANCAR {
private:
    int NUMARCONT;
    double SOLD;
    float RATADOBANZII;

public:
    void setAccountNumber(int accountNum);
    void setBalance(double balance);
    void setInterestRate(float rata);
    int getAccountNumber();
    double getBalance();
    float getInterestRate();
    double calculateInterest();
    void deposit(double amount);
    void withdraw(double amount);
};

#endif