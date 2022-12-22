/*
*****************************************************************************
						  Workshop - #4 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {
	//these functions are private btw :)
	bool Seat::validate(int row, char letter)const {
		return ((row >= 1 && row <= 4 && (letter == 'A'|| letter == 'B'|| letter == 'E'|| letter == 'F'))|| (((row >= 7 && row <= 15) || (row >= 20 && row <= 37))&&
			(letter=='A'|| letter =='B' || letter =='C' || letter=='D'|| letter=='E'||letter=='F')));
	}
	Seat& Seat::alAndCp(const char* str) {
		pName = nullptr;
		if (str != nullptr) {
			pName = new char[strlen(str) + 1]; // dynamic allocation
			strcpy(pName, str);
			if (strlen(pName) > 40) {pName[40] = '\0';} // incase pName is too long cuts it to 39 + 1 for null terminator
		}
		return *this;
	}
	//Safe Empty State 
	Seat& Seat::reset() { //deallocates memory Classtype Function return type.
		delete[] pName;pName = nullptr;rowNum = 0;sLetter = '\0';
			return *this; //returns altered classtype. would return classtype regardless after function is done running.
	}
	bool Seat::isEmpty() const {return pName == nullptr;} //return true if pName is empty
	bool Seat::assigned() const {return validate(rowNum, sLetter);} //returns true if valid.
	//constructors
	Seat::Seat() {pName = nullptr;reset();} // gets called when the class is declared without parameters;
	Seat::Seat(const char* passengerName) { // gets called when the class is declared with parameters.
		pName = nullptr;reset();
		if (passengerName != nullptr) {alAndCp(passengerName);}
	}
	Seat::Seat(const char* passengerName, int row, char letter) { 
		pName = nullptr;reset();
		bool result = validate(row, letter);
		if (passengerName != nullptr && result) {
			alAndCp(passengerName);
			rowNum = row;sLetter = letter;
		}
		if (passengerName != nullptr && (!result)) { 
			alAndCp(passengerName);
		}
	}
	//destructors
	Seat::~Seat() {delete[] pName;pName = nullptr;} //destructor deallocates dynamic memory. gets called when function member goes out of scope.
	//Modifiers and Quieries
	Seat& Seat::set(int row, char letter) {
		bool result = validate(row, letter); //validates the entries
		if (result) {rowNum = row;sLetter = letter;} // if entry is valid stores in private member variable
		else {rowNum = 0;sLetter = '\0'; } //else if invalid sets membervariables to zero 
		return *this; //returns the class itself.
	}
	int Seat::row()const {return rowNum;} //returns RowNumber
	char Seat::letter()const {return sLetter;} // returns seat Letter
	const char* Seat::passenger()const {return pName;} // returns passenger Name
	//display 
	std::ostream& Seat::display(std::ostream& coutRef)const { //reference of the ostream object Cout.(defined in header)
		if (pName != nullptr && pName[0] != '\0') { //conditions for display
			if (validate(rowNum, sLetter)) {
				coutRef.width(40); // sets max width
				coutRef.fill('.'); //sets '.' as filler 
				coutRef.setf(ios::left); //sets to left align
				coutRef << pName; //ostream object redirection for pName
				coutRef.unsetf(ios::left); // unsets the alignment
				coutRef.fill(' '); //reamoves the filler
				coutRef << " " << rowNum << sLetter; //ostream object reditection 
			}
			else {
				coutRef.width(40);
				coutRef.fill('.');
				coutRef.setf(ios::left);
				coutRef << pName;
				coutRef.unsetf(ios::left);
				coutRef.fill(' ');
				coutRef << " ___";
				/*coutRef <<pName <<cout.setf(ios::left)<<cout.width(40) << cout.fill('.') << " ___";
				cout.unsetf(ios::left);
				coutRef.fill(' ');*/
			}
		}
		else {
			coutRef << "Invalid Seat!";
		}
		return coutRef;
	}
	std::istream& Seat::read(std::istream& cinRef) { //istream object reference cin (defined in header function)
		reset();char m_name[71];int m_row;char m_seat; 
		if (cinRef) { // if cin was successfull implemented in main.cpp
			cinRef.getline(m_name,71,',');cinRef >> m_row; // getline command using cinRef object. Variable, count, and delimiter; CinRef cins the value to the variable m_row;
			cinRef >> m_seat;cinRef.ignore(1000, '\n'); //cinRef.ignore clears input buffer count and metadelim ends the inputbuffer clearing when it meants the delim;
			if (m_name != nullptr) {
				alAndCp(m_name);set(m_row, m_seat);
			}
		}
		return cinRef;
	}
}