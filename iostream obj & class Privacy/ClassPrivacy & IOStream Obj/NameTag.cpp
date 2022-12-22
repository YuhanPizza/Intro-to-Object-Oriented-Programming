/*
*****************************************************************************
						  Workshop - #3 (P2)
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
#include "NameTag.h"
#include <cstring>

using namespace std;

namespace sdds {
	void NameTag::set(const char* cc_name) {
		strcpy(name, cc_name);
	}
	bool NameTag::verify()const {
		return name[0] != '\0';
	}
	void NameTag::display() {
			display(name);// when you call name here since you change the parameters you have to add an int to that argument
	}
	void NameTag::display(char* name) { // add it to this function parameters
		cout << "******************************\n";
		cout << "* ";
		cout.setf(ios::left);
		cout.width(27);
		cout << name << "*\n";
		cout.unsetf(ios::left);
		cout << "******************************\n";
		//U HAVE TO CREATE ANOTHER FUNCTION that takes in the length. here. 
	}
	//char NameTag::Name() {
	//	return name[];
	//}

}