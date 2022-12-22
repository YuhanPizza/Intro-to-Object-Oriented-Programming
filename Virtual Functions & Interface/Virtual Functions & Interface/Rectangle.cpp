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
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
  Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label)
  {
    int _compareWidth = strlen(LblShape::label()) + 2;

    //if condition is not passed rectangle will be set to empty
    if (width > _compareWidth && height > 3) {
      m_width = width;
      m_height = height;
    }
  }

  void Rectangle::getSpecs(std::istream &istr)
  {
    int width;
    int height;
    char comma;
    bool exit = false;

    do {
      // read the label by using base class's getSpecs
      LblShape::getSpecs(istr);

      // read the value of the m_width and the comma and the value of the m_height
      istr >> width >> comma >> height;

      if (!istr) {
        istr.clear();
        istr.ignore(1000, '\n');
      }
      else {
        // it will ignore The rest of the characters up to and including '\n'
        istr.ignore();
        m_width = width;
        m_height = height;
        exit = true;
      }
    } while (!exit);
  }

  void Rectangle::draw(std::ostream &ostr) const
  {
    if (m_width > 0 && m_height >> 0) {
      //label and symbol following the provided format
      //first line
      ostr << '+';
      ostr.width(m_width - 2);
      ostr.fill('-');
      ostr << '-' << '+' << endl;

      //second line
      ostr << '|';
      ostr.width(m_width - 2);
      ostr.fill(' ');
      ostr << left << LblShape::label() << '|' << endl;

      //middle lines
      for (unsigned int i = 0; i < (m_height - 3); i++) {
        ostr << '|';
        ostr.width(m_width - 2);
        ostr.fill(' ');
        ostr << ' ' << '|' << endl;
      }

      //last line
      ostr << '+';
      ostr.width(m_width - 2);
      ostr.fill('-');
      ostr << '-' << '+';
    }
  }
}