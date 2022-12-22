/*
*****************************************************************************
                          Workshop - #5 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
       //constructor
      Apartment(int number, double balance);

      //invalid 
      void isEmpty();

      //display
      std::ostream& display()const;

      //quirey 
      operator bool()const;
      bool operator~()const;
      operator int()const;
      operator double()const;

      //modifier
      Apartment& operator=(Apartment& AB);
      Apartment& operator=(int number);
      Apartment& operator +=(double addVal);
      Apartment& operator -=(double deductVal);
      Apartment& operator <<(Apartment& right);
      Apartment& operator >>(Apartment& right);
      //helper function
      friend double operator+(const Apartment& left, const Apartment& right);
      friend double operator+=(double& value, const Apartment& right);
   };
   double operator+(const Apartment& left, const Apartment& right);
   double operator+=(double& value, const Apartment& right);
}

#endif // SDDS_APARTMENT_H_