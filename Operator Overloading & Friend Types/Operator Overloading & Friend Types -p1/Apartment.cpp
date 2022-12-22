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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{   
    //unirary operator
    bool Apartment::operator~()const {
        return (m_balance <= 0.00001);
    }
    //safe empty state
    void Apartment::isEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // conversion operators
    Apartment::operator int() const{
        return m_number;
    }
    Apartment::operator double() const{
        return m_balance;
    }
    Apartment::operator bool()const {
        return (m_number >= 1000 && m_number <= 99999);
    }
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   //display
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }
   //assignment operator
   Apartment& Apartment::operator=(Apartment& AB) {
       if (*this && AB) {
           double t = 0;
           int it = 0;
           it = m_number;
           m_number = AB.m_number;
           AB.m_number = it;
           t = m_balance;
           m_balance = AB.m_balance;
           AB.m_balance = t;
       }
       return *this;

   }
   Apartment& Apartment::operator=(int number) {
       if ((*this)&& (number >= 1000 && number <= 9999) ){
               m_number = number;
       }
       else{ isEmpty(); }
       return *this;
   }
   Apartment& Apartment::operator +=(double addVal) {
       if (*this && addVal > 0) {
           m_balance += addVal;
       }
       return *this;
   }
   Apartment& Apartment::operator -=(double deductVal) {
       if ((*this && deductVal >= 0) && (m_balance > deductVal)) {
           m_balance -= deductVal;
       }
       return *this;
   }
   Apartment& Apartment::operator <<(Apartment& right) {
       if ((*this && right) && (double(*this) != double(right))) {
           m_balance += double(right);
           right.m_balance = 0;
       }
       return *this;
   }
   Apartment& Apartment::operator >>(Apartment& right) {
       if ((*this && right)&&(double(*this) != double(right))) {
           right += double(*this);
           m_balance = 0;
       }
       return *this;
   }
   double operator+(const Apartment& left, const Apartment& right) { //friend function or Helper Function
       double val = 0;
       if (left && right) {
           val = (double(left) + double(right));
       }
       return val;
   }
   double operator+=(double& value,const Apartment& right) { //friend function or helper function
       if (right) {
           value += double(right);
       }
       return value;
   }

}