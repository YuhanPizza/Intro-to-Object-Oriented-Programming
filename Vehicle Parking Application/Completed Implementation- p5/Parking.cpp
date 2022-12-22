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
#include <string>
#include <fstream>
#include "Parking.h"

using namespace std;

namespace sdds {
	//query
	bool Parking::isEmpty() {
		return (m_File == nullptr);
	};
	void Parking::parkingstatus() {
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout<<m_noOfSpots - m_noOfParked << "    *****" << endl;
	};

	//Action functions
	void Parking::ParkVehicle() {//parks the vehicle function
		int select = m_Vmenu.run();
		switch (select) {
		case 1:
			for (int i = 0; i < m_noOfSpots; i++) {
				if (m_ParkingSpots[i] == nullptr) {
					m_ParkingSpots[i] = new Car;
					m_ParkingSpots[i]->setCsv(true);
					m_ParkingSpots[i]->read(i + 1);
					cout << "\n";
					cout << "Parking Ticket" << "\n";
					m_ParkingSpots[i]->setCsv(false);
					m_ParkingSpots[i]->write();
					cout << "\n";
					m_noOfParked++;
					pause();
					cout << "\n";
				}
			}

			break;
		case 2:
			for (int i = 0; i < m_noOfSpots; i++) {
				if (m_ParkingSpots[i] == nullptr) {
					m_ParkingSpots[i] = new Motorcycle;
					m_ParkingSpots[i]->setCsv(true);
					m_ParkingSpots[i]->read(i + 1);
					cout << "\n";
					cout << "Parking Ticket" << "\n";
					m_ParkingSpots[i]->setCsv(false);
					m_ParkingSpots[i]->write();
					cout << "\n";
					m_noOfParked++;
					pause();
					cout << "\n";
				}
			}
			break;
		case 3:
			cout << "Parking cancelled" << endl;
			pause();
			break;

		default:
			break;
		}
	};

	void Parking::ReturnVehicle() {//removes the vehicle from parking
		string g_license;
		int exit = 1;
		int index = -1;
		cout << "Return Vehicle" << "\n";
		cout << "Enter Licence Plate Number: ";
		while (exit) {
			cin >> g_license;
			if (!cin || g_license.length() < 1 || g_license.length() > 8) {
				cout << "Invalid Licence Plate, try again: ";
				while (getchar() != '\n');
				cin.clear();
			}
			else {
				exit = 0;
			}
		}
		char* temp;
		temp = new char[g_license.length() + 1];
		strcpy(temp, g_license.c_str());
		for (int i = 0; i < (int)strlen(temp); i++) {
			temp[i] = toupper(temp[i]);
		}
		for (int i = 0; i < m_noOfParked; i++) {
			if (m_ParkingSpots[i] != nullptr) {
				if (strcmp(m_ParkingSpots[i]->fetchLicense(), temp) == 0) {
					index = i;
				}
			}
		}
		if (index != -1) {
			cout << "\n";
			cout << "Returning:" << "\n";
			m_ParkingSpots[index]->write();
			cout << "\n";
			delete m_ParkingSpots[index];
			m_ParkingSpots[index] = nullptr;
			m_noOfParked = m_noOfParked - 1;
		}
		else {
			cout << "\n";
			cout << "License plate " << temp << " Not found" << "\n";
			cout << "\n";
		}
		delete[] temp;
	};

	void Parking::ListParkedVehicles() {//lists all parked vehicles 
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_noOfSpots; i++) {
			if (m_ParkingSpots[i] != nullptr) {
				m_ParkingSpots[i]->setCsv(false);
				m_ParkingSpots[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	};
	

	void Parking::findVehicle() {//find the vehicle index
		string g_license;
		int exit = 1;
		int index = -1;
		cout << "Vehicle Search" << "\n";
		cout << "Enter Licence Plate Number: ";
		while (exit) {
			cin >> g_license;
			if (!cin || g_license.length() < 1 || g_license.length() > 8) {
				cout << "Invalid Licence Plate, try again: ";
				while (getchar() != '\n');
				cin.clear();
			}
			else {
				exit = 0;
			}
		}
		char* temp;
		temp = new char[g_license.length()+1 ];
		strcpy(temp, g_license.c_str());
		for (int i = 0; i < (int)strlen(temp); i++) {
			temp[i] = toupper(temp[i]);
		}
		for (int i = 0; i < m_noOfParked; i++) {
			if (strcmp(m_ParkingSpots[i]->fetchLicense(),temp) == 0) {
				index = i;
			}
		}
		if (index != -1) {
			cout << "\n";
			cout << "Vechicle found: " << "\n";
			m_ParkingSpots[index]->write();
			cout << "\n";
		}
		else {
			cout << "\n";
			cout << "License plate " << temp << " Not found"<<"\n";
			cout << "\n";
		}
		delete[] temp;
	};
	bool Parking::CloseParking() {//closes the parking removes all unparked vehicle
		bool cVal = false;
		if (m_noOfParked > 0) {
			char choice;
			int cond = 1;
			cout << "This will This will Remove and tow all remaining vehicles from the parking!!" << "\n";
			cout << "Are you sure? (Y)es/(N)o: ";
			do {

				cin >> choice;
				while (getchar() != '\n');
				cin.clear();
				if (choice == 'y' || choice == 'Y') {
					cond = 0;
					cVal = true;
					cout << "Closing Parking"<<endl;
					for (int i = 0; i < m_noOfSpots; i++) {
						if (m_ParkingSpots[i] != nullptr) {
							cout << '\n' << "Towing request" << endl;
							cout << "*********************" << endl;
							m_ParkingSpots[i]->write();
						}
					}
					ofstream ofs;
					ofs.open(m_File, std::ofstream::out | std::ofstream::trunc);
					ofs.close();

				}
				else if (choice == 'n' || choice == 'N') {
					cond = 0;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
			} while (cond == 1);
		}
		else {
			cout << "Closing Parking" << "\n";
			cVal = true;
		}
		return cVal;
	};
	bool Parking::ExitParkingApp() {//quits the app 

		bool eVal = false;
		char choice;
		int cond = 1;
		cout << "This will This will terminate the program!!" << "\n";
		cout << "Are you sure? (Y)es/(N)o: ";
		do {

			cin >> choice;
			while (getchar() != '\n');
			cin.clear();
			if (choice == 'y' || choice == 'Y') {
				cout << "Exiting program!" << "\n";
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
		ofstream file(m_File);
		if (file.is_open()) {
			for (int i = 0; i < m_noOfSpots; i++) {
				if (m_ParkingSpots[i] != nullptr) {
					m_ParkingSpots[i]->setCsv(true);
					m_ParkingSpots[i]->write(file);
				}
			}
		}
	};

	//public:

	//constructor
	Parking::Parking(const char* file, int noOfSpots) {
		m_File = nullptr;
		if (file != nullptr && strlen(file) > 0 && noOfSpots >= 10 && noOfSpots <= 100) {
			m_File = new char[strlen(file) + 1];
			strcpy(m_File, file);
			if (noOfSpots < MAX_NO_OF_SPOTS && noOfSpots >= 10) {
				m_noOfSpots = noOfSpots;
			}
			for (int i = 0; i < MAX_NO_OF_SPOTS; i++) {
				m_ParkingSpots[i] = nullptr;
			}

			if (loadDataFile()) {
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
	void Parking::pause() {
		cout << "Press <ENTER> to continue....";
		cin.ignore(1000, '\n');
	}
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
					break;
				case 2:
					ReturnVehicle();
					pause();
					cout << "\n";
					break;
				case 3:
					ListParkedVehicles();
					cout << "Press <ENTER> to continue....";
					cin.ignore(1000, '\n');
					break;
				case 4:
					findVehicle();
					pause();
					cout << "\n";
					break;
				case 5:
					if (CloseParking()) {
						flag = 0;
					}
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
		bool value = false;
		if ((strlen(m_File) > 0) && (!isEmpty())) {
			ifstream fin(m_File);
			if (!fin.is_open()) {
				value = true;
			}
			else {
				int exit = 0;
				do {
					char c;
					fin.get(c);
					fin.ignore();
					if (c == 'M' || c == 'C') {
						if (c == 'M') {
							int spot;
							fin >> spot;
							fin.ignore();
							m_ParkingSpots[spot-1] = new Motorcycle;
							m_ParkingSpots[spot - 1]->setCsv(false);
							m_ParkingSpots[spot-1]->read(spot,fin);
							m_noOfParked++;
							value = true;
						}
						if(c == 'C') {
							int spot;
							fin >> spot;
							fin.ignore();
							m_ParkingSpots[spot-1] = new Car;
							m_ParkingSpots[spot - 1]->setCsv(false);
							m_ParkingSpots[spot-1]->read(spot,fin);
							m_noOfParked++;
							value = true;
						}
						c = '\0';
					}
					else {
						exit = 1;
					}
					
				} while (m_noOfParked < m_noOfSpots && exit == 0);
			}
		}
		else {
			value = true;
		}
		return value;
	};

	//destructor
	Parking::~Parking() {
		delete[] m_File;
		for (int i = 0; i < MAX_NO_OF_SPOTS; i++) {
			delete m_ParkingSpots[i];
		}
	};
};