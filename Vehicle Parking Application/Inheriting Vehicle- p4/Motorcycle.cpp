/*
*****************************************************************************
						  Milestone 4
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
#include <string>
#include <cstring>
#include "Motorcycle.h"

using namespace std;
namespace sdds {
	//constructor calls Vehicle constructor
	Motorcycle::Motorcycle() {//sets the car to invalid safe empty state;
		m_sideCar = false;
		Vehicle::setEmpty();
	}
	Motorcycle::Motorcycle(const char* license, const char* model, int no) :Vehicle(license, model, no) {// create an invalid safe empty state.
		m_sideCar = false;
	}

	//rule of threes
	Motorcycle::Motorcycle(Motorcycle& src) : Vehicle(src) {//copy constructor
		m_sideCar = src.m_sideCar;
	};
	//destructor
	Motorcycle::~Motorcycle() {
		m_sideCar = false;
	};
	//assignment constructor
	Motorcycle& Motorcycle::operator=(Motorcycle& src) {
		m_sideCar = src.m_sideCar;
		Vehicle::operator=(src);
		return *this;
	};

	//iostream objects
	ostream& Motorcycle::writeType(ostream& ostr)const {
		if (Vehicle::isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle"<<"\n";
		}
		return ostr;
	};
	ostream& Motorcycle::write(ostream& ostr)const {
		if (!isEmpty()) {
			writeType(ostr);
			Vehicle::write(ostr);
			if (!isCsv()) {
				if (m_sideCar == true) {
					ostr << "With Sidecar" << endl;
				}
			}
			else {
				if (m_sideCar == false) {
					ostr << "0" << endl;
				}
				else {
					ostr << "1" << endl;
				}
			}
		}
		else {
			ostr << "Invalid Motorcycle Object" << endl;
		}
		return ostr;
	};
	istream& Motorcycle::read(istream& istr) {
		char temp[5];
		if (!isCsv()) {
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			int flag = 1;
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			
			while (flag) {
				istr >> temp;
				if (!istr) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					while (getchar() != '\n');
					istr.clear();
				}
				else if (((temp[0] == 'Y' || temp[0] == 'N') || (temp[0] == 'y' || temp[0] == 'n'))  && (temp[1] == '\0')) {
					if (temp[0] == 'Y' || temp[0] == 'y') {
						m_sideCar = true;
					}
					else if (temp[0] == 'N' || temp[0] == 'n') {
						m_sideCar = false;
					}
					flag = 0;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					while (getchar() != '\n');
					istr.clear();
				}
			}
		}
		else {
			Vehicle::read(istr);
			istr.getline(temp, 5, '\n');
			istr.clear();
			if (strcmp(temp, "0") == 0) {
				m_sideCar = false;
			}
			else {
				m_sideCar = true;
			}
		}

		return istr;
	};
}