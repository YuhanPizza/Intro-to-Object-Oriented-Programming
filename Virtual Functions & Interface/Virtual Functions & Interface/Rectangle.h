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

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
  class Rectangle : public LblShape
  {
    unsigned int m_width  {0};
    unsigned int m_height {0};

  public:
    Rectangle() = default;
    Rectangle(const char *_label, int _width, int _height);
    virtual ~Rectangle() = default;

    void getSpecs(std::istream &istr);
    void draw(std::ostream &ostr) const;
  };
}
#endif