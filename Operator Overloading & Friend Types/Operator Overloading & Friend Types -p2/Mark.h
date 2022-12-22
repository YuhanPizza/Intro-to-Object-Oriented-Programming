/*
*****************************************************************************
						  Workshop - #5 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
	class Mark {
		int m_mark = 0;

	public:
		//constructors
		Mark();
		Mark(int value);

		//fetching variables
		operator int()const;
		operator char()const;
		operator double()const;

		//query
		operator bool()const;
		bool operator~()const;
		bool operator < (const Mark& M)const;
		bool operator > (const Mark& M)const;
		bool operator <= (const Mark& M)const;
		bool operator >= (const Mark& M)const;
		bool operator != (const Mark& M)const;
		bool operator == (const Mark& M)const;
		//prefix
		Mark& operator++();
		Mark& operator--();

		//postfix
		Mark operator++(int);
		Mark operator--(int);

		Mark& operator=(int value);

		Mark& operator+=(int value);
		Mark& operator-=(int value);

		Mark operator+(int value)const;
		Mark operator+(const Mark& M)const;

		Mark& operator<<(Mark& M);
		Mark& operator>>(Mark& M);
		friend int operator+(int& value, const Mark& right);
		friend int operator+=(int& value, const Mark& right);
		friend int operator-=(int& value, const Mark& right);
	};
	int operator+(int& value, const Mark& right);
	int operator+=(int& value, const Mark& right);
	int operator-=(int& value, const Mark& right);
}

#endif