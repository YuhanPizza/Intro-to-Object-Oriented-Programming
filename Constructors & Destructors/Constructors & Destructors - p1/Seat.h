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
#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_
#include <iostream>

namespace sdds {
   class Seat {
	   char* pName;
	   int rowNum;
	   char sLetter;

	   bool validate(int row, char letter)const;
	   Seat& alAndCp(const char* str);

   public:
	   //Safe Empty State
	   Seat& reset();
	   bool isEmpty() const;
	   bool assigned() const;

	   //constructors
	   Seat();
	   Seat(const char* passengerName);
	   Seat(const char* passengerName, int row, char letter);
	   //destructors

	   ~Seat();

	  //Modifiers and Quieries
	   Seat& set(int row, char letter);
	   int row()const;
	   char letter()const;
	   const char* passenger()const;

	   //display 
	   std::ostream& display(std::ostream& coutRef = std::cout)const;
	   std::istream& read(std::istream& cinRef = std::cin);
   };
}
#endif // !SDDS_SEAT_H_


