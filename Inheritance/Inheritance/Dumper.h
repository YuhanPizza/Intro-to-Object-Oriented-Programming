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
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{
	//class Dumper is derived from VehicleBasic base class
	class Dumper : public VehicleBasic {
		double m_MaxWeight; //holds cargo weight limit
		double m_Weight; //holds current cargo limit
	public:
		//constructors
		Dumper();
		Dumper(const char* g_licensePlate, int g_year,int g_cap, const char* g_address);

		//query
		bool loaddCargo(double cargo); //if cargo limit is within max weight stores it and value of m_Weight is changed returns true.
		bool unloadCargo(); // if current Weight is not 0 changes the value to zero and returns true

		//ostream object cout
		std::ostream& write(std::ostream& os=std::cout);
		//istream object cin
		std::istream& read(std::istream& in = std::cin);

		
	};
	//helper functions
	std::ostream& operator<<(std::ostream& os,Dumper Org);//calls the ostream object
	std::istream& operator>>(std::istream& is,Dumper& Org);//calls the istream object
}
#endif

