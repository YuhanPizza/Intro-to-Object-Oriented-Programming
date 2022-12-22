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
#ifndef _SDDS_HTMLTEXT_H
#define _SDDS_HTMLTEXT_H
#include "Text.h"
#include <iostream>

namespace sdds{
	//derived class: base class
	class HtmlText : public Text{
		//char variable
		char* m_title = nullptr;

	public:
		//constructor
		HtmlText() = default; //default 
		HtmlText(const char* title); //overloaded
		HtmlText(const HtmlText& src); //copy
		//destructor
		 ~HtmlText();

		 //void return ostream object
		 void write(std::ostream& ostr) const;

		 //assignment operator overload
		 HtmlText& operator=(const HtmlText& org);
	};
}
#endif 
