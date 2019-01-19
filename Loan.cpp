//
// Created by salim msaddek on 19/01/2019.
//

#include "Loan.h"

Loan::Loan() {
    int choice;
    std::cout << "Chose which operation you want to perform:" << std::endl;
    std::cout << "1 for instalment" << std::endl;
    std::cout << "2 for closing balance" << std::endl;
    std::cout << "3 for periodic interest rate" << std::endl;
    std::cout << "4 for number of periods" << std::endl;
    std::cout << "Use your keyboard to chose: ";
    std::cin >> choice;
    while (choice < 1 or choice > 4) {
        std::cout << "You must chose a number between 1 and 4: ";
        std::cin >> choice;
    }
    switch (choice) {
        case 1:
            this->computeInstalment();
            break;
        case 2:
            this->computeClosingBalance();
            break;
        case 3:
            this->computePeriodicInterestRate();
            break;
        case 4:
            this->computeN();
            break;
    }
}

void Loan::setInstalment() {
    std::cout << "Chose a value for instalment: ";
    std::cin >> this->instalment;
    std::cout << "The instalment is " << this->instalment << "." << std::endl;
}

void Loan::setClosingBalance() {
    std::cout << "Chose a value for closing balance: ";
    std::cin >> this->closingBalance;
    std::cout << "The closing balance is " << this->closingBalance << "." << std::endl;
}

void Loan::setPeriodicInterestRate() {
    std::cout << "Chose a value for periodic interest rate (as percentage): ";
    std::cin >> this->periodicInterestRate;
    this->periodicInterestRate /= 100;
    std::cout << "The periodic interest rate is " << this->periodicInterestRate * 100 << "%." << std::endl;
}

void Loan::setN() {
    std::cout << "Chose a value for number of periods: ";
    std::cin >> this->n;
    while (this->n < 1) {
        std::cout << "The number of periods must be at least of 1: ";
        std::cin >> this->n;
    }
}

void Loan::computeInstalment() {
    this->setClosingBalance();
    this->setPeriodicInterestRate();
    this->setN();

    this->instalment = this->periodicInterestRate * this->closingBalance * (1 + 1 / (pow(1 + this->periodicInterestRate, this->n) - 1));
    std::cout << "The instalment is " << this->instalment << "." << std::endl;
}

void Loan::computeClosingBalance() {
    this->setInstalment();
    this->setPeriodicInterestRate();
    this->setN();

    this->closingBalance = this->instalment / (this->periodicInterestRate * (1 + 1 / (pow(1 + this->periodicInterestRate, this->n) - 1)));
    std::cout << "The closing balance is " << this->closingBalance << "." << std::endl;
}

void Loan::computePeriodicInterestRate() {
    this->setInstalment();
    this->setClosingBalance();
    this->setN();

    double i = 0.01;
    while (i < 1) {
        double localInstalment = i * this->closingBalance * (1 + 1 / (pow(1 + i, this->n) - 1));
        if (round(localInstalment * 100) / 100 == round(this->instalment * 100) / 100) {
            break;
        }
        i += 0.01;
    }
    if (i == 1) {
        std::cout << "Sorry, the result has not been found." << std::endl;
    } else {
        std::cout << "The periodic interest rate is " << i * 100 << "%." << std::endl;
    }
}

void Loan::computeN() {
    this->setInstalment();
    this->setClosingBalance();
    this->setPeriodicInterestRate();
    this->n = round(log(this->instalment / (this->instalment - this->closingBalance * this->periodicInterestRate)) / log(1 + this->periodicInterestRate));
    std::cout << "The number of periods is " << this->n << "." << std::endl;
}
