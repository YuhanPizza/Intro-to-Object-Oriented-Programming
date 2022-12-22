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
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		bool m_CarWash = false;
	public:
		//constructor calls Vehicle constructor
		Car(); //sets the car to invalid safe empty state;
		Car(const char* license, const char* model, int no = 0); // create an invalid safe empty state.


		//rule of threes
		Car(Car& src); //copy constructor
		//destructor
		virtual ~Car();
		//assignment constructor
		Car& operator=(Car& src);

		//iostream objects
		std::ostream& writeType(std::ostream& ostr = std::cout)const;
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);
	};
}
#endif