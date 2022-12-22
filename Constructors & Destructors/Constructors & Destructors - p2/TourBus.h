/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include "TourTicket.h"
namespace sdds {
    class TourBus {
        TourTicket* m_ticket;
        int pSize;
    public:
        //safe empty state
        void Reset();

        //constructors
        TourBus();
        TourBus(int pSize);

        //destructors
        ~TourBus();

        //quirey and Modifiers
        bool validTour()const;
        TourBus& board();

        //display function
        void startTheTour()const;
    };
}
#endif // !SDDS_TOURTICKET_H_
