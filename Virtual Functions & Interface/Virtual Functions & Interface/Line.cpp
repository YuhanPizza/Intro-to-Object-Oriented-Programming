/*
*****************************************************************************
                          Workshop 8
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
  Line::Line(const char* label, int length) : LblShape(label)
  {
    if (length > 0)
      m_length = length;
  }

  void Line::getSpecs(std::istream &istr)
  {
    int length;
    bool exit = false;

    do {
      // read the label by using base class's getSpecs
      LblShape::getSpecs(istr);

      // read the value of the m_length
      istr >> length;

      if (!istr) {
        istr.clear();
        istr.ignore(1000, '\n');
      }
      else {
        istr.ignore();
        m_length = length;
        exit = true;
      }
    } while (!exit);
  }

  void Line::draw(std::ostream &ostr) const
  {
    if (m_length > 0 && LblShape::label()) {;
      // draw the label and symbol 
      ostr.fill('=');
      ostr.width(m_length);
      ostr.setf(ios::left);
      ostr << LblShape::label(); //prints out the label from a function in LblShape 
      ostr.unsetf(ios::left);
      ostr.fill(' ');
    }
  }
}
