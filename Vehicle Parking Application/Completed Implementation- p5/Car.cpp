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
#include "Car.h"

using namespace std;
namespace sdds {
	//constructor calls Vehicle constructor
	Car::Car() {//sets the car to invalid safe empty state;
		m_CarWash = false;
		Vehicle::setEmpty();
	}
	Car::Car(const char* license, const char* model, int no) :Vehicle(license, model, no) {// create an invalid safe empty state.
		m_CarWash = false;
	}

	//rule of threes
	Car::Car(Car& src) : Vehicle(src) {//copy constructor
		m_CarWash = src.m_CarWash;
	};
	//destructor
	Car::~Car() {
		m_CarWash = false;
	};
	//assignment constructor
	Car& Car::operator=(Car& src) {
		m_CarWash = src.m_CarWash;
		Vehicle::operator=(src);
		return *this;
	};

	//iostream objects
	ostream& Car::writeType(ostream& ostr)const {
		if (Vehicle::isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car" << "\n";
		}
		return ostr;
	};
	ostream& Car::write(ostream& ostr)const {
		if (!isEmpty()) {
			writeType(ostr);
			Vehicle::write(ostr);
			if (!isCsv()) {
				if (m_CarWash == false) {
					ostr << "Without Carwash" << endl;
				}
				else {
					ostr << "With Carwash" << endl;
				}
			}
			else {
				if (m_CarWash == false) {
					ostr << "0" << endl;
				}
				else {
					ostr << "1" << endl;
				}
			}
		}
		else {
			ostr << "Invalid Car Object" << endl;
		}
		return ostr;
	};
	istream& Car::read(int value,istream& istr) {
		char temp[5];
		if (isCsv()) {

			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(value,istr);
			int flag = 1;
			cout << "Carwash while parked? (Y)es/(N)o: ";

			while (flag) {
				istr >> temp;
				if (!istr) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					while (getchar() != '\n');
					istr.clear();
				}
				else if (((temp[0] == 'Y' || temp[0] == 'N') || (temp[0] == 'y' || temp[0] == 'n')) && (temp[1] == '\0')) {
					if (temp[0] == 'Y' || temp[0] == 'y') {
						m_CarWash = true;
					}
					else if (temp[0] == 'N' || temp[0] == 'n') {
						m_CarWash = false;
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
			Vehicle::read(value,istr);
			istr.getline(temp, 5, '\n');
			istr.clear();
			if (strcmp(temp, "0") == 0) {
				m_CarWash = false;
			}
			else {
				m_CarWash = true;
			}
		}

		return istr;
	};
}