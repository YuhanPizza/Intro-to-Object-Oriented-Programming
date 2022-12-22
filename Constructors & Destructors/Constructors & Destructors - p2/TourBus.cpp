#define CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "TourBus.h"
using namespace std;
namespace sdds {
    //constructors
    TourBus::TourBus() {
        m_ticket = nullptr;
        //Reset();
        pSize = 0;
    }
    TourBus::TourBus(int m_size) {
        m_ticket = nullptr;
        //Reset();
        pSize = 0;
        if (m_size == 4 || m_size == 16 || m_size == 22) {
            pSize = m_size;
            m_ticket = new TourTicket[m_size];
        }
    }

    //destructor
    TourBus::~TourBus() {
        delete[]m_ticket;
        m_ticket = nullptr;
        pSize = 0;
        //Reset();
    }

    //Quiery
    bool TourBus::validTour() const{
        return m_ticket != nullptr;
    }

    //modifier
    TourBus& TourBus::board() {
        char passenger[71];
        cout << "Boarding " << pSize << " Passengers:\n";
        for (int i = 1; i < pSize + 1; i++) {
            cout << i << "/" << pSize << "- " << "Passenger Name: ";
            cin.getline(passenger, 71, '\n');
            m_ticket[i - 1].issue(passenger);
        }
        return *this;
    }

    //display function
    void TourBus::startTheTour() const{
        if (m_ticket[0].valid()) {
            cout << "Starting the tour....\n" << "Passenger List:\n" << "|" << cout.width(3);
            cout.setf(ios::left);
            cout << "Row" << " | " << cout.width(40) << "Passenger Name" << " | "<< cout.width(4) << "Num" << "|\n";
            cout.unsetf(ios::left);
            //cout << "|Row | Passenger Name                           | Num |" << '\n';
            cout << "+----+------------------------------------------+-----+\n";
            for (int i = 0; i < pSize; i++) {
                cout << "|  " << i+1 << " ";
                m_ticket[i].display();
                cout << "\n";
            }
            cout << "+----+------------------------------------------+-----+\n";
        }
        if(pSize > 0 && (!m_ticket[0].valid())) {
            cout << "Cannot start the tour, the bus is not fully boarded!\n";
        }
    }
}