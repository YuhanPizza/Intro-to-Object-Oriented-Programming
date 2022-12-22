/*
*****************************************************************************
						  Milestone 2
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_PARKING_H_
#define SDDS_PARKING_H
#include<iostream>
#include "Menu.h"

using namespace std;


namespace sdds
{
	class Parking
	{
		//object type class menu
		Menu m_Parking;
		Menu m_Vmenu;

		//dynamically allocated char string to be set with Constructor
		char* m_File = nullptr;

		//query
		bool isEmpty();
		

		//Action functions
		void parkingstatus();
		void ParkVehicle(); //parks the vehicle function
		void ReturnVehicle(); //removes the vehicle from parking
		void ListParkedVehicles(); //lists all parked vehicles 
		void findVehicle(); //find the vehicle index
		bool CloseParking(); //closes the parking removes all unparked vehicle
		bool ExitParkingApp(); //quits the app 
		void SaveDataFile(); //save function to filename only activates when exiting app

	public:

		//constructor
		Parking(const char* file);

		//runs the program
		int run();

		//loadDatafile function takes the filename string as filename
		bool loadDataFile();

		//destructor
		~Parking();
	};
}
#endif 