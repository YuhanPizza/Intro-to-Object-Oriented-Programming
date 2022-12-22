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
#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
namespace sdds{
	const char& Text::operator[](int index) const{
		return m_content[index];
		
	}

	Text::~Text(){
		delete[] m_content;
	}



	Text::Text(const Text& a){
		*this = a;
	}

	unsigned Text::getFileLength(std::istream& is){
		unsigned len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// tell what is the positions (end position = size)
			len = unsigned(is.tellg());
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}

	istream& Text::read(istream& istr){
		delete[] m_content;
		int i = 0;
		m_content = new char[getFileLength(istr) + 1];
		while (istr.get(m_content[i])){
			i++;
		}
		m_content[i] = '\0';
		if (i){
			istr.clear();
		}
		return istr;
	}

	void Text::write(ostream& ostr) const{
		ostr << m_content;
	}

	Text& Text::operator=(const Text& org){
		if(this != &org){ 
			delete[] m_content;
			m_content = nullptr;
			if (org.m_content){
				m_content = new char[strlen(org.m_content) + 1];
				strcpy(m_content, org.m_content);
			}
		}
		return *this;
	}

	ostream& operator<<(ostream& ostr,  const Text& src){
		src.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Text& src){
		src.read(istr);
		return istr;
	}
}