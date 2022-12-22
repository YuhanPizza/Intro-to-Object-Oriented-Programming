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
#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include "NameTag.h"

namespace sdds {
	class TagList {
		NameTag* m_nameTag;
		int m_add;
		int m_len;
		int m_num;

	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
	};
}
#endif