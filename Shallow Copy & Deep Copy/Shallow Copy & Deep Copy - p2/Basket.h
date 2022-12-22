/*
*****************************************************************************
						  Workshop - #6 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>


namespace sdds {
	struct Fruit {
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms

		//query method added this for saftey checks
		operator bool()const;
	};


	class Basket {
		struct Fruit* m_fruits; //dynamic memory of fruit struct
		int m_sizeFruits; //size of fruits array
		double m_price;  //price of the basket
	public:
		//constructors
		Basket(); //default
		Basket(Fruit Fruit[], int size, double price); //overloaded 
		Basket(const Basket& Org);// Copy

		//assignment operator
		Basket& operator=(const Basket& Org);

		//set empty state
		void setEmpty();
		
		//deallocate
		void deallocate();

		//Destructor
		~Basket();

		void setPrice(double price); //updates the price attribute to the value received as parameter
		
		//query
		operator bool()const; //if the basket contains any fruits

		//overloaded operator
		Basket& operator+=(Fruit& add); //operator that receives as a parameter an object of type and adds it to the dynamic Fruits array

		//helper functions
		friend std::ostream& operator<<(std::ostream& os, const Basket& N); //ostream object
	};
	std::ostream& operator<<(std::ostream& os, const Basket& N);
}
#endif
