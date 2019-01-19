//
// Created by salim msaddek on 19/01/2019.
//

#ifndef UNTITLED2_LOAN_H
#define UNTITLED2_LOAN_H

#include <iostream>
#include <math.h>

class Loan {
public:
    Loan();

    void setInstalment();
    void setClosingBalance();
    void setPeriodicInterestRate();
    void setN();

    void computeInstalment();
    void computeClosingBalance();
    void computePeriodicInterestRate();
    void computeN();
private:
    double instalment;
    double closingBalance;
    double periodicInterestRate;
    long n;
};

#endif //UNTITLED2_LOAN_H
