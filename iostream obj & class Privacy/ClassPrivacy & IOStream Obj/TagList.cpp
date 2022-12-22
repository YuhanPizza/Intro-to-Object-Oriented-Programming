/*
*****************************************************************************
						  Workshop - #3 (P2)
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
#include "TagList.h"
#include <cstring>

using namespace std;

namespace sdds {
		void TagList::set() {
			m_nameTag = nullptr;
			m_add = 0;
			m_len = 0;
			m_num = 0;
		}
		void TagList::set(int num) {
			cleanup();
			if (num > 0) {
				m_num = num;
				m_add = 0;

				m_nameTag = new NameTag[num];
			}
		}
		void TagList::add(const NameTag& nt) {
			/*cleanup();*/
			m_nameTag[m_add] = nt;
			m_add++;
			//u can add an int function that takes the m_length = strlen(name);
		}
		void TagList::print() {
			for (int i = 0; i < m_num; i++) {
				m_nameTag[i].display();
			}
		}
		void TagList::cleanup() {
			delete[]m_nameTag;
			set();
		}
}