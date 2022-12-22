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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Parking.h"

using namespace std;

namespace sdds{
	//query
	bool Parking::isEmpty() {
		return (m_File == nullptr);
	};
	void Parking::parkingstatus() {
		cout << "****** Valet Parking ******" << endl;
	};

	//Action functions
	void Parking::ParkVehicle() {//parks the vehicle function
		int select = m_Vmenu.run();
		switch (select) {
		case 1:
			cout << "---------------------------------" << endl;
			cout << "Parking Car" << endl;
			cout << "---------------------------------" << endl;

			break;
		case 2:
			cout << "---------------------------------" << endl;
			cout << "Parking Motorcycle" << endl;
			cout << "---------------------------------" << endl;
			break;
		case 3:
			cout << "---------------------------------" << endl;
			cout << "Cancelled parking" << endl;
			cout << "---------------------------------" << endl;
			break;

		default:
			break;
		}
	};

	void Parking::ReturnVehicle() {//removes the vehicle from parking
		cout << "---------------------------------" << endl;
		cout << "Returning Vehicle" << endl;
		cout << "---------------------------------" << endl;
	};

	void Parking::ListParkedVehicles() {//lists all parked vehicles 
		cout << "---------------------------------" << endl;
		cout << "Listing Parked Vehicles" << endl;
		cout << "---------------------------------" << endl;
	};

	void Parking::findVehicle() {//find the vehicle index
		cout << "---------------------------------" << endl;
		cout << "Finding a Vehicle" << endl;
		cout << "---------------------------------" << endl;
	}; 
	bool Parking::CloseParking() {//closes the parking removes all unparked vehicle
		bool cVal = false;
		char choice;
		int cond = 1;
		cout << "This will close the parking; All the vehicles will be removed!" << "\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			
			cin >> choice;
			while (getchar() != '\n');
			cin.clear();
			if (choice == 'y' || choice == 'Y') {
				cout << "Ending application!";
				cond = 0;
				cVal = true;
			}
			else if (choice == 'n' || choice == 'N') {
				cond = 0;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (cond == 1);
		return cVal;
	}; 
	bool Parking::ExitParkingApp() {//quits the app 

		bool eVal = false;
		char choice;
		int cond = 1;
		cout << "This will terminate the application and save the data!" << "\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		do {

			cin >> choice;
			while (getchar() != '\n');
			cin.clear();
			if (choice == 'y' || choice == 'Y') {
				cout << "Exiting application!"<<"\n";
				cond = 0;
				eVal = true;
			}
			else if (choice == 'n' || choice == 'N') {
				cond = 0;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		} while (cond == 1);
		return eVal;
	}; 
	void Parking::SaveDataFile() {//save function to filename only activates when exiting app
		cout << "---------------------------------" << endl;
		cout << "Saving data into "<<m_File << endl;
		cout << "---------------------------------" << endl;
	}; 

//public:

	//constructor
	Parking::Parking(const char* file) {
		m_File = nullptr;
		if (file != nullptr && strlen(file) > 0) {
			m_File = new char[strlen(file) + 1];
			strcpy(m_File, file);


			if (loadDataFile()) {
				cout << "---------------------------------" << endl;
				cout << "loading data from "<<m_File<< endl;
				cout << "---------------------------------" << "\n" << endl;
				m_Parking = "Parking Menu, select an action:";

				m_Parking.add("Park Vehicle");
				m_Parking.add("Return Vehicle");
				m_Parking.add("List Parked Vehicles");
				m_Parking.add("Find Vehicle");
				m_Parking.add("Close Parking (End of day)");
				m_Parking.add("Exit Program");

				m_Vmenu = "Select type of the vehicle:";
				m_Vmenu.setIndent(1);
				m_Vmenu.add("Car");
				m_Vmenu.add("Motorcycle");
				m_Vmenu.add("Cancel");
			}
			
		}
		else {
			cout << "Error in data file" << "\n";
		}
	};

	//runs the program
	int Parking::run() {
		if (m_File) {
			int flag = 1;
			while (flag) {
				parkingstatus();

				int select = m_Parking.run();
				switch (select) {
				case 1:
					ParkVehicle();
					cout << "\n";
					break;
				case 2:
					ReturnVehicle();
					cout << "\n";
					break;
				case 3:
					ListParkedVehicles();
					cout << "\n";
					break;
				case 4:
					findVehicle();
					cout << "\n";
					break;
				case 5:
					if (CloseParking()) {
						flag = 0;
					}
					cout << "\n";
					break;
				case 6:
					if (ExitParkingApp()) {
						flag = 0;
						SaveDataFile();
					}
					break;
				default:
					break;
				}
			}
		}
		return !isEmpty();
	};

	//loadDatafile function takes the filename string as filename
	bool Parking::loadDataFile() {
		return ((strlen(m_File) > 0) && (!isEmpty()));
	};

	//destructor
	Parking::~Parking() {
		delete[] m_File;
		m_File = nullptr;
	};
};