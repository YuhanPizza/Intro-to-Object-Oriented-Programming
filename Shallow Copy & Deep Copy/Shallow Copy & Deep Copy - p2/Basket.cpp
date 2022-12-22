/*
*****************************************************************************
						  Workshop - #6 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Basket.h"

using namespace std;

namespace sdds {
	//query method
	Fruit::operator bool()const {
		return (m_name && m_qty);
	}

	//constructors
	Basket::Basket() {//default
		setEmpty();
	} 
	Basket::Basket(Fruit Fruit[], int size, double price) {//overloaded 
		setEmpty();
		if (Fruit) {
			m_price = price;
			m_sizeFruits = size;
			m_fruits = new struct Fruit[size];
			for (int i = 0; i < size; i++) {
				m_fruits[i] = Fruit[i];
			}
		}
	} 
	Basket::Basket(const Basket& Org) {// Copy
		setEmpty();
		*this = Org;
	}

	//assignment operator
	Basket& Basket::operator=(const Basket& Org) {
		deallocate();
		setEmpty();
		m_sizeFruits = Org.m_sizeFruits;
		m_price = Org.m_price;
		m_fruits = new struct Fruit[m_sizeFruits];
		for (int i = 0; i < m_sizeFruits; i++) {
			m_fruits[i] = Org.m_fruits[i];
		}
		return *this;
	}

	//safe empty state
	void Basket::setEmpty() {
		m_fruits= nullptr;
		m_sizeFruits = 0;
		m_price = 0;
	}

	//deallocation method
	void Basket::deallocate() {
		delete[]m_fruits;
		m_fruits = nullptr;
	}

	//Destructor
	Basket::~Basket() {
		delete []m_fruits;
		m_fruits = nullptr;
		m_sizeFruits = 0;
		m_price = 0;
	}

	void Basket::setPrice(double price) {//updates the price attribute to the value received as parameter
		m_price = price;
	} 

	//query method
	Basket::operator bool()const {//if the basket contains any fruits
		return (m_fruits != nullptr && m_sizeFruits != 0);
	} 

	//overloaded operator
	Basket& Basket::operator+=(Fruit& add) { //operator that receives as a parameter an object of type and adds it to the dynamic Fruits array
		if (add) {
			Fruit* temp;
			temp = new struct Fruit[m_sizeFruits + 1];
			int i = 0;
			for (int j = 0; j < m_sizeFruits; j++,i++) {
				temp[i] = m_fruits[j];
			}
			temp[i] = add;
			m_sizeFruits += 1;
			delete[]m_fruits;
			m_fruits = new struct Fruit[m_sizeFruits];
			for (int i = 0; i < m_sizeFruits; i++) {
				m_fruits[i] = temp[i];
			}
			delete[]temp;
			temp = nullptr;
		}
		return *this;
	}

	//helper functions
	std::ostream& operator<<(std::ostream& os, const Basket& N) {
		if (N) {
			os << "Basket Content:" << "\n";
			for (int i = 0; i < N.m_sizeFruits; i++) {
				os.setf(ios::right); os << setw(10) << N.m_fruits[i].m_name<<":"; os.unsetf(ios::right); os << " " << N.m_fruits[i].m_qty<<"kg\n";
			}
			os <<fixed<<setprecision(2)<< "Price: " << N.m_price << "\n";
		}
		else {
			os << "The basket is empty!\n";
		}
		return os;
	}
}