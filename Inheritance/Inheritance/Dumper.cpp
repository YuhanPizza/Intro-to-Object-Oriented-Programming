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
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;

namespace sdds
{
	//constructors
	Dumper::Dumper() {
		m_MaxWeight = 0;
		m_Weight = 0;
	};
	Dumper::Dumper(const char* g_licensePlate, int g_year, int g_cap,const char* g_address):VehicleBasic(g_licensePlate,g_year) { //imports the values passed in base function
		m_MaxWeight = g_cap;
		m_Weight = 0;
		NewAddress(g_address); //calls NewAddress function from base class
	};
	//query
	bool Dumper::loaddCargo(double cargo) { //returns true or false
		bool potato = false;
		if (m_Weight + cargo < m_MaxWeight) { //if current cargo + added cargo parameter does not exceed MaxWeight
			m_Weight += cargo; // add cargo to m_Weight
			potato = true; //returns true if condition has passed
		}
		return potato;
	};
	bool Dumper::unloadCargo() { //returns true or false
		bool potato = false;
		if (m_Weight != 0) { //if weight is not zero
			m_Weight = 0; // unloads it weight is zero 
			potato = true;
		}
		return potato;

	};
	//ostream object cout
	ostream& Dumper::write(std::ostream& os) {
		VehicleBasic::write(os); //calls base function write 
		os << " | " << m_Weight << "/" << m_MaxWeight;
		return os; //returns the ostream object cout
	}
	//istream object cin
	istream& Dumper::read(std::istream& in) {
		VehicleBasic::read(in); //calls base function read
		cout << "Capacity: ";
		in >> m_MaxWeight;
		while (getchar() != '\n');
		in.clear();
		cout << "Cargo: ";
		in >> m_Weight;
		while (getchar() != '\n');
		in.clear();
		return in; //returns istream object cin
	};
	//overloaded insertion operator 
	ostream& operator<<(std::ostream& os, Dumper Org) {
		return Org.write(os);
	};
	//overloaded extraction operator
	istream& operator>>(std::istream& is, Dumper& Org) {
		return Org.read(is);
	};
}

