/*
*****************************************************************************
                          Workshop - #10
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

/*
                            ====> Search Template Function<====
  Collection is a template class. It receives a Car or Student or Employee class as a type.
  Collection Template class is used as an array.
  The data was then added using the template member function defined in the template collection class.
  There is also a Template member variable from collection Template class because the key values from the different classes
  recieved by the collection class is different.
  As a result, as with the first template function, the types are determined during the compilation phase.
  Then, a "=="(equality) operator is called for each class to compare if it matches.
  If match is found, call the template function "add" in the Collection class to add the data.
*/

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

namespace sdds
{
    template <typename T1, typename T2>//  class type in Collection and array in turn the searched array member will then be added to the collection
    bool search(Collection<T1>& src_obj, const T1* src_arr, int src_num, T2 src_key) { //recieve the given typename for the keyvalue
        bool result = false; //sets bool value as false 

        for (int i = 0; i < src_num; i++) {
            if (src_arr[i] == src_key) { // Call "==" operator corresponding to each type
                src_obj.add(src_arr[i]);   // Call the template function "add" in Collection template class, adds the object to the latest index for the class.
                result = true; //sets the bools value as true
            }
        }
        return result; //returns true or false if matches are found
    }
}
#endif // !SDDS_SEARCH_H_
