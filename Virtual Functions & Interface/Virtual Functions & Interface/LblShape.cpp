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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
  const char* LblShape::label()const{ //returns m_label
    return m_label;
  }
  //constructor
  LblShape::LblShape(const char *label)
  {
    if (label && label[0] != '\0') {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
    }
  }

  //destructor
  LblShape::~LblShape()
  {
    //memory deallocation method
    if (m_label) {
      delete[] m_label;
      m_label = nullptr;
    }
  }

  void LblShape::getSpecs(std::istream &istr)
  {
      string label;

     //reads a comma delimiter Cstring from istream
      getline(istr, label, ',');

    //copy the Cstring into the newly created memory
      delete[] m_label;
      m_label = new char[strlen(label.c_str()) + 1]; //c_str() converts a string to an array of characters and attaches a null terminator at the last member of the array
      strcpy(m_label, label.c_str());

    ////alternative code
    //char label[50];
    
    //// Reads a comma delimiter Cstring from istream
    //istr.getline (label, 51, ',');
    
    //// copy the Cstring into the newly created memory
    //delete[] m_label;
    //m_label = new char[strlen(label) + 1];
    //strcpy(m_label, label);
  }
}