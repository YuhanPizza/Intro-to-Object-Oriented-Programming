/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
    struct PostalPopulation
    {
        char* pCode;
        int pop;
    };
    void DecreasingSort();
    bool load(const char filename[]);
    bool load(PostalPopulation& post);
    void display(const PostalPopulation& code);
    void display();
    void deallocateMemory();//part 1 function
}
#endif // SDDS_POPULATION_H_