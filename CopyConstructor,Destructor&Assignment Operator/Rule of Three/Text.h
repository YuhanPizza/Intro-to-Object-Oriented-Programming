/*
*****************************************************************************
						  Workshop - #9
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef _SDDS_TEXT_H
#define _SDDS_TEXT_H
#include <iostream>

namespace sdds{
	class Text{
		char* m_content = nullptr;

	protected:

		const char& operator[](int index)const;

	public:

		Text() = default;
		virtual ~Text();
		Text(const Text& a);
		unsigned getFileLength(std::istream& is);
		virtual  std::istream& read(std::istream& istr);
		virtual void write(std::ostream& ostr) const;
		Text& operator=(const Text& org);
	};
	std::ostream& operator<<(std::ostream& ostr, const Text& src);
	std::istream& operator>>(std::istream& istr, Text& src);
}
#endif // !_SDDS_TEXT_H
