/*
*****************************************************************************
						  Workshop - #7
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;
namespace sdds
{
	//constructor
	VehicleBasic::VehicleBasic() {
		m_year = 0;
	};
	//constructor 
	VehicleBasic::VehicleBasic(const char* g_license, int g_year) {
		strcpy(m_license, g_license);
		m_year = g_year;
		strcpy(m_address, "Factory");
	};
	//New address display change function 
	void VehicleBasic::NewAddress(const char* address) {
		if (strcmp(m_address, address)!=0) {
			cout << "|";
			cout << setw(8);
			cout.setf(ios::right);
			cout << m_license;
			cout.unsetf(ios::right);
			cout << "| |";
			cout << setw(20);
			cout.setf(ios::right);
			cout << m_address;
			cout.unsetf(ios::right);
			strcpy(m_address, address);
			cout << " ---> ";
			cout << setw(20);
			cout.setf(ios::left);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);
		}
	};
	//output cout object
	ostream& VehicleBasic::write(std::ostream& os) {
		os << "| " << m_year << " | " << m_license << " | " << m_address;
		return os;
	};
	//input cin object
	istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_year;
		while (getchar() != '\n');
		in.clear();
		cout << "License plate: ";
		in >> m_license;
		while (getchar() != '\n');
		in.clear();
		cout << "Current location: ";
		in >> m_address;
		while (getchar() != '\n');
		in.clear();
		return in;
	};
	//overloaded insertion operator 
	ostream& operator<<(std::ostream& os, VehicleBasic Org) {
		return Org.write(os);
	};
	//overloaded extraction operator
	std::istream& operator>>(std::istream& is, VehicleBasic& Org) {
		return Org.read(is);
	};
}
