/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CC.h"

using namespace std;

namespace sdds {
    bool CC::validate(const char* name,
        unsigned long long cardNo,
        short cvv,
        short expMon,
        short expYear)const {
        if (name != nullptr && strlen(name) > 2) {
            if (cardNo >= 4000000000000000 && cardNo <= 4099999999999999) {
                if (cvv >= 100 && cvv <= 999) {
                    if (expMon > 0 && expMon < 13) {
                        if (expYear >= 22 && expYear <= 32) {
                            return true;
                        }
                        //cout << "Invalid Expiry Year" << endl;
                    }
                    //cout << "Invalid Expiry month" << endl;
                }
                //cout << "CVV code Invalid " << endl;
            }
            //cout << "Invalid Card Number" << endl;
        }
        //cout << "Insufficient Name Length" << endl;
        return false;
    }

    void CC::prnNumber()const {
        unsigned long long a, b, c, d, value, value2;
        value = cardNo;
        a = value / 1000000000000ull;
        value2 = a * 1000000000000ull;
        value = value - value2;
        b = value / 100000000ull;
        value2 = b * 100000000ull;
        value = value - value2;
        c = value / 10000ull;
        value2 = c * 10000ull;
        value = value - value2;
        d = value / 1ull;

        printf("%04llu %04llu %04llu %04llu", a, b, c, d);
    }

    void CC::set() {
        name = nullptr;
        cardNo = 0;
        cvv = 0;
        expMon = 0;
        expYear = 0;
    }
    void CC::cleanUp() {
        delete[]name;
        set();
    }
    bool CC::isEmpty()const {
        bool result = false;
        if (name == nullptr) {
            bool result = true;
            return result;
        }
        return result;
    }
    void CC ::set(const char* cc_name,
        unsigned long long cc_no,
        short m_cvv,
        short m_expMon,
        short m_expYear) {
        cleanUp();
        bool result = validate(cc_name,cc_no,m_cvv,m_expMon,m_expYear);
        if (result) {
            
            
            name = new char[strlen(cc_name) + 1];
            strcpy(name, cc_name);

            cardNo = cc_no;
            cvv = m_cvv;
            expMon = m_expMon;
            expYear = m_expYear;
        }
        else {
            cleanUp();
        }
        
    }
    bool CC::read() {
        cleanUp();
        char name[71] = {"\0"};
        unsigned long long creditNum = 0;
        short cardVerify = 0;
        short year = 0;
        short month = 0;
        cout << "Card holder name: ";
        cin.getline(name, 71,'\n');//i use this command to get the line up to 71 chars long and/or it meets the delimiter '\n'
        if (cin) { //nested if statment. 
            cout << "Credit card number: ";
            cin >> creditNum;
            if (cin) { // these cin if conditions basically check if the value was stored if not it exits the if statments.
                cout << "Card Verification Value (CVV): ";
                cin >> cardVerify;
                if (cin) {
                    cout << "Expiry month and year (MM/YY): ";
                    cin >> month;
                    cin.ignore();
                    cin >> year;
                    bool result = validate(name, creditNum, cardVerify, month, year);
                    if (result) {
                        set(name, creditNum, cardVerify, month, year);
                        return result;
                    }
                    
                }

            }
        }
        cin.clear(); //you see it clears when it doesnt enter one of the if statments it ends up here since its a nested if statment
        cin.ignore(1000,'\n');
        return false;
    }
    void CC::display(int row ) const {
        bool result = isEmpty();
        if (!result) {
            if (row <= 0) {
                cout << "Name: " << name << "\n";
                cout << "Creditcard No: "; prnNumber(); cout << "\n";
                cout << "Card Verification Value: " << cvv << "\n";
                cout << "Expiry Date: " << expMon << "/" << expYear << "\n";
            }
            if(row > 0){
                char cc_name[30];
                if (strlen(name) > 30) {
                    for (int i = 0; i < 30; i++) {
                        cc_name[i] = name[i];
                    }
                    cc_name[29] = '\0';
                }
                else {
                    strcpy(cc_name, name);
                }
                cout << "| ";
                cout.width(3);
                cout.setf(ios::right);
                cout << row;
                cout.unsetf(ios::right);
                cout << " | ";
                cout.width(30);
                cout.setf(ios::left);
                cout << cc_name << " | ";
                cout.unsetf(ios::left);
                prnNumber();
                cout << " | ";
                cout << cvv; 
                cout << " | ";
                cout.width(2);
                cout.setf(ios::right);
                cout << expMon;
                cout << "/" << expYear << " |" << "\n";
                cout.unsetf(ios::right);
                /*cout << "inside file ";*/


            }
        }
        else {
            cout << "Invalid Credit Card Record\n";
        }
    }
}