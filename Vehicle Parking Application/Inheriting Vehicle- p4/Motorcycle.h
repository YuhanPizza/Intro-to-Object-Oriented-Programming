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
#ifndef SDDS_MOTORCYCLE_H_
#define SDDS_MOTORCYCLE_H_
#include "Vehicle.h"

namespace sdds {
	class Motorcycle : public Vehicle {
		bool m_sideCar = false;
	public:
		//constructor calls Vehicle constructor
		Motorcycle(); //sets the car to invalid safe empty state;
		Motorcycle (const char* license, const char* model, int no = 0); // create an invalid safe empty state.


		//rule of threes
		Motorcycle(Motorcycle& src); //copy constructor
		//destructor
		virtual ~Motorcycle();
		//assignment constructor
		Motorcycle& operator=(Motorcycle& src);

		//iostream objects
		std::ostream& writeType(std::ostream& ostr = std::cout)const;
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);
	};
}
#endif