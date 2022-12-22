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

#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
  class LblShape : public Shape //inheritance from base Shape 
  {
    char *m_label {nullptr}; 
  protected:
      //function to grabe the value of m_label
    const char* label()const;

  public:
      //constructors
    LblShape() = default; //create a default constructor
    LblShape(const char *_label); //overloaded constructor
    //virtual destructor 
    virtual ~LblShape();

    // prevent copying
    LblShape(const LblShape &src) = delete;
    LblShape &operator=(const LblShape &src) = delete;

    // Override the base class's getSpecs pure virtual function
    void getSpecs(std::istream &istr);
  };
}
#endif