/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include <string.h>
#include "File.h"
#include <iostream>


using namespace std;
namespace sdds {
    int pNum;
    int popNum;

    PostalPopulation* can;

    void DecreasingSort() { //this function sorts the structs;
        int i;
        int j;
        PostalPopulation num;

        for (i = 1; i < pNum; i++) { // from variable 1 to the last variable compared to population Number
            num = can[i]; //struct PostalPopulation num is given the value of PostalPopulation can[0];

            for (j = i - 1; j >= 0 && can[j].pop > num.pop; j--) { // compares values until j reaches to 0 and if can[j].pop is highier than num.pop;
                can[j + 1] = can[j];  //stores value one array member highier j+1;
            }

            can[j + 1] = num; // stores the lowest value to the first member of the array;
        }
    }

    bool load(const char filename[]) {
        int i = 0;
        bool result = openFile(filename);
        if (result) {
            pNum = noOfRecords();
            can = new PostalPopulation[pNum];
            for (int j = 0; j < pNum; j++) {
                i += load(can[j]);
            }
            if (i != pNum) {
                cout << "Error" << endl;
            }
            closeFile();
            return result;
        }
        else {
            cout << "Failure to Open" << filename << endl;
        }
        closeFile();
        return result;
    }

    bool load(PostalPopulation& popCode) {
        char value[6];
        bool result = (read(value) && read(popCode.pop));
        if (result) {
            popCode.pCode = new char[strlen(value) + 1];
            strcpy(popCode.pCode, value);

            return result;
        }
        return result;
    }
    void display(const PostalPopulation& popCode) {
        cout << popCode.pCode << ":  " << popCode.pop << endl;
    }

    void display() {
        cout << "Postal Code: population" << "\n";
        cout << "-------------------------" << "\n";
        DecreasingSort();
        for (int i = 0; i < pNum; i++) {
            cout << i + 1 << "- ";
            display(can[i]);
            popNum += can[i].pop;
        }
        cout << "-------------------------" << "\n";
        cout << "Population of Canada: " << popNum << "\n";
    }

    void deallocateMemory() {
        for (int i = 0; i < pNum; i++) {
            delete[] can[i].pCode;
            can[i].pCode = nullptr;
        }

        delete[] can;
        can = nullptr;
    }
}