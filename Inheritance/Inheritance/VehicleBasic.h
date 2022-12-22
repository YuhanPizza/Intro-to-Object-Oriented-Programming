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
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	class VehicleBasic {
		char m_license[9]; //holds the license plate string value
		char m_address[64]; //holds the address 
		int m_year; //hold the year number

	public:
		//constructors
		VehicleBasic();
		VehicleBasic(const char* g_licenseNum, int g_year);
		//changing address display
		void NewAddress(const char* address);
		//ostream object cout
		std::ostream& write(std::ostream& os = std::cout);
		//istream object cout
		std::istream& read(std::istream& in = std::cin);
	};
	//helper functions
	std::ostream& operator<<(std::ostream& os, VehicleBasic Org); //calls the ostream object 
	std::istream& operator>>(std::istream& is, VehicleBasic& Org); //calls the istream object
}

#endif

