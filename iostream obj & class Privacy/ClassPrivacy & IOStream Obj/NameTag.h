/*
*****************************************************************************
						  Workshop - #3 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_


namespace sdds {
	class NameTag {
		char name[50];
	public:
		void set(const char* name);
		void display();
		void display(char* name);
		bool verify()const;
		//char Name();
	};
}
#endif