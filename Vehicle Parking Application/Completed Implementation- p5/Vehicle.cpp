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
#include "Vehicle.h"

using namespace std;
namespace sdds {
	Vehicle::Vehicle() {
		m_license[0] = '\0';
		m_model = nullptr;
		m_park = 0;
	};
	Vehicle::Vehicle(Vehicle& org) {
		delete[]m_model;
		if (org.m_model != nullptr) {
			strcpy(m_license, org.getLicensePlate());
			m_model = new char[strlen(org.m_model) + 1];
			strcpy(m_model, org.m_model);
			m_park = org.m_park;
		}
		else {
			setEmpty();
		}
	};
	Vehicle::Vehicle(const char* license, const char* model, int no) {
		if ((license != nullptr && strlen(license) > 0 && strlen(license) < 8) && (model != nullptr && strlen(model) > 2)) {
			setLicense(license);
			setMakeModel(model);
			setParkingSpot(no);
		}
		else {
			delete[]m_model;
			setEmpty();
		}
	};
	Vehicle::~Vehicle() {
		delete[] m_model;
	}
	void Vehicle::setEmpty() {
		m_license[0] = { '\0' };
		m_model = nullptr;
		m_park = 0;
	};
	bool Vehicle::isEmpty() const {
		return m_model == nullptr;
	};
	const char* Vehicle::getLicensePlate()const {
		return m_license;
	};
	char* Vehicle::getMakeModel() {
		return m_model;
	};
	int Vehicle::getParkingSpot() {
		return m_park;
	};
	const char* Vehicle::fetchLicense()const {
		return m_license;
	};
	void  Vehicle::setLicense(const char* g_license) {
		if (g_license != nullptr && strlen(g_license) < 8) {
			strcpy(m_license, g_license);
			int length = strlen(m_license);
			for (int i = 0; i < length; i++) {
				m_license[i] = toupper(m_license[i]);
			}
		}
		else {
			delete[]m_model;
			setEmpty();
		}
	};
	void Vehicle::setMakeModel(const char* g_model) {
		if (g_model != nullptr) {
			int length = strlen(g_model);
			if (m_model) {
				delete[]m_model;
				m_model = nullptr;
			}
			m_model = new char[length + 1];
			for (int i = 0; i < length; i++) {
				m_model[i] = g_model[i];
			}
			m_model[length] = '\0';
		}
		else {
			delete[]m_model;
			setEmpty();
		}
	};
	void Vehicle::setParkingSpot(int no) {
		if (no >= 0) {
			m_park = no;
		}
		else {
			delete[]m_model;
			setEmpty();
		}
	};

	ostream& Vehicle::write(ostream& ostr)const {
		if (m_model != nullptr && m_park >= 0) {
			if (isCsv()) {
				ostr << m_park << "," << m_license << "," << m_model << ",";
			}
			else {
				ostr << "Parking Spot Number: "; (m_park == 0) ? ostr << "N/A" << "\n" : ostr << m_park << "\n";
				ostr << "License Plate: " << m_license << "\n";
				ostr << "Make and Model: " << m_model << "\n";
			}
		}
		else {
			ostr << "Invalid Vehicle Object" << "\n";
		}

		return ostr;
	};
	istream& Vehicle::read(int value, istream& istr) {
		char licence[8], model[60];
		if (!isCsv()) {
			int exit = 1;
			do {
				m_park = value;
				istr.getline(licence, 8, ',');
				if (!istr) {
					cout << "Invalid License Plate, try again: ";
					while (getchar() != '\n');
					istr.clear();
				}
				else {
					setLicense(licence);
					istr.getline(model, 60, ',');
					if (!istr) {
						cout << "Invalid Make and model, try again: ";
						while (getchar() != '\n');
						istr.clear();
					}
					else {
						setMakeModel(model);
						exit = 0;
					}
				}
			} while (exit == 1);
		}
		else {
			m_park = value;
			int exit = 1;
			cout << "Enter License Plate Number: ";
			while (exit) {
				istr.getline(licence, 8, '\n');
				if (!istr || strlen(licence) > 8) {
					cout << "Invalid License Plate, try again: ";
					while (getchar() != '\n');
					istr.clear();

				}
				else {
					exit = 0;
				}
			}
			setLicense(licence);
			exit = 1;
			cout << "Enter Make and Model: ";
			while (exit) {
				istr.getline(model, 60, '\n');
				if (!istr) {
					cout << "Invalid Make and model, try again: ";
					while (getchar() != '\n');
					istr.clear();

				}
				else if (strlen(model) < 2) {
					cout << "Invalid Make and model, try again: ";
					istr.clear();
				}
				else {
					setMakeModel(model);
					exit = 0;
				}
			}
		}
		return istr;
	}
	Vehicle& Vehicle::operator=(Vehicle& src) {
		delete[]m_model;
		setEmpty();
		strcpy(m_license, src.getLicensePlate());
		m_model = new char[strlen(src.getMakeModel()) + 1];
		strcpy(m_model, src.getMakeModel());
		m_park = src.m_park;
		ReadWritable::operator=(src);
		return *this;
	};

	bool operator==( Vehicle& left,  Vehicle& right) {
		bool value = (strcmp(left.fetchLicense(), right.fetchLicense ()) == 0);
		return value;
	}

	bool operator==( Vehicle& left, char* plate) {
		char temp[8];
		bool value = false;
		for (int i = 0; i < int(sizeof(plate)); i++) {
			temp[i] = toupper(plate[i]);
		}
		value = (strcmp(left.fetchLicense(), temp) == 0);
		return value;
	}
};
