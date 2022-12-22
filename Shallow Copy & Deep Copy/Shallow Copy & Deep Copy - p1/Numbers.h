/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers{}; // holds the address of the dynamic array of doubles holding the number collection
      char* m_filename{}; // holds the name of the file associated with the class (if it is the original object and not a copy)
      bool m_isOriginal; // true if this object is the original (and not a copy)
      int m_numCount; // holds the number of values in the m_number dynamic array
      bool isEmpty()const; //bool returns if m_numbers is empty
      void setEmpty(); //clear emptry state
      void deallocate(); //deallocation method acts like a destructor but as a function
      void setFilename(const char* filename); // sets the file name of the class filename 
   public:
      Numbers(); //default constructor
      Numbers(const char* filename); //Creates an original instance of the Numbers class by receiving the data file name as a constant Cstring
      double average()const; //Returns the average of the double numbers in the list.
      double max()const; //Returns the largest double number in the list
      double min()const; //Returns the smallest double number in the list
      ~Numbers(); //destructor deallocation method

      //to do
      Numbers(Numbers& Org);
      Numbers& operator=(Numbers& Org);
      Numbers& sort(bool ascending);
      Numbers operator-();
      Numbers operator+();
      int numberCount()const;
      bool load();
      void save();
      
      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& ostr)const;
      friend std::ostream& operator<<(std::ostream& os, const Numbers& N);
      friend std::istream& operator>>(std::istream& istr, Numbers& N);
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

