/*
*****************************************************************************
						  Milestone 3
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_READWRITABLE_H_
#define SDDS_READWRITABLE_H_
#include <iostream>

namespace sdds {
	class ReadWritable
	{
		bool m_value;

	public:

		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		virtual ReadWritable& operator=(ReadWritable& src);
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		virtual std::istream& read(std::istream& istr = std::cin) = 0;

	};

	std::ostream& operator<<(std::ostream& ostr, ReadWritable& src);
	std::istream& operator>>(std::istream& istr, ReadWritable& src);
}
#endif 