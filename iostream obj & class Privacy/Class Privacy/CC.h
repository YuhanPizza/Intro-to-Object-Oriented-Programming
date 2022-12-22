/*
*****************************************************************************
                          Workshop - #3 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_CC_H_
#define SDDS_CC_H_
namespace sdds {
    class CC {
        //class members private
        char* name;
        unsigned long long cardNo;
        short cvv;
        short expMon;
        short expYear;
        //private class functions
        bool validate(const char* name,
            unsigned long long cardNo,
            short cvv,
            short expMon,
            short expYear)const;
        void prnNumber()const;

        //public class functions
    public:
        void set();
        void cleanUp();
        bool isEmpty()const;
        void set(const char* cc_name,
            unsigned long long cc_no,
            short cvv,
            short expMon,
            short expYear);
        bool read();
        void display(int row = 0) const;
    };
}
#endif