/*
*****************************************************************************
						  Milestone 5
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include "ReadWritable.h"
#include <iostream>
#define MAX_LENGTH 8

namespace sdds {
	class Vehicle : public ReadWritable {
		char m_license[MAX_LENGTH] = { 0 };
		char* m_model = nullptr;
		int m_park;

	protected:
		//query
		void setEmpty();
		bool isEmpty()const;

		//set variables
		void setMakeModel(const char* g_model);

		//fetchers
		char* getMakeModel();
		const char* getLicensePlate()const;

	public:
		Vehicle();
		Vehicle(Vehicle& org);
		virtual ~Vehicle();
		Vehicle(const char* license, const char* model, int no = 0);

		//set variables
		void setParkingSpot(int no);
		void setLicense(const char* g_license);


		//helper functions 
		int getParkingSpot();
		const char* fetchLicense()const;

		Vehicle& operator=(Vehicle& src);

		//iostream variables
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(int value,std::istream& istr = std::cin );
		virtual	std::ostream& writeType(std::ostream& ostr = std::cout)const = 0;
	};
	//queries 
	bool operator==(Vehicle& left, Vehicle& right);
	bool operator==(Vehicle& left, const char* plate);
}
#endif 