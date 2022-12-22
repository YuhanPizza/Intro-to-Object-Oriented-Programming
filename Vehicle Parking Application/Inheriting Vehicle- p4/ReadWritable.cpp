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
#include "ReadWritable.h"

using namespace std;
namespace sdds {
	ReadWritable::ReadWritable() {
		m_value = false;
	}
	ReadWritable::~ReadWritable() {
	}
	bool ReadWritable::isCsv()const {
		return m_value;
	};
	void ReadWritable::setCsv(bool value) {
		m_value = value;
	};
	ReadWritable& ReadWritable::operator=(ReadWritable& src) {
		m_value = src.m_value;
		return *this;
	};
	ostream& operator<<(ostream& ostr, ReadWritable& src) {
		src.write(ostr);
		return ostr;
	};
	istream& operator>>(istream& istr, ReadWritable& src) {
		src.read(istr);
		return istr;
	};
}
