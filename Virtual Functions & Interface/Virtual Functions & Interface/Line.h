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

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
    //derived class       base class
  class Line : public LblShape //inherits from base class LblShape
  {
    unsigned int m_length {0};

  public:
    Line() = default; //creates a default constructor
    Line(const char *_label, int _length); //overloaded constructor
    virtual ~Line() = default;
    // Override the base class's getSpecs virtual function
    void getSpecs(std::istream &istr);
    // Override the base class's draw virtual function
    void draw(std::ostream &ostr) const;
  };
}
#endif