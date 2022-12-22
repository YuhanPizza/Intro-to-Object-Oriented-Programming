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

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
  //  Pure virtual function
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual void draw(std::ostream &ostr) const  = 0;
    virtual void getSpecs(std::istream &istr) = 0;
  };

  std::ostream &operator<<(std::ostream &ostr, const Shape &src);
  std::istream &operator>>(std::istream &istr, Shape &src);
}

#endif