/*
*****************************************************************************
						  Milestone 1
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
#include <iomanip>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace sdds {
	MenuItem::MenuItem() {
		m_name = nullptr;
	}
	//safe empty state
	void MenuItem::setEmpty() {
		delete[] m_name;
		m_name = nullptr;
	};

	//ostream object display function
	std::ostream& MenuItem::display(std::ostream& ostr) const{ //called this in display function for I
		if (m_name) {
			ostr << m_name << "\n";
		}
		return ostr;
	};
	
	//menu item overloaded constructor
	MenuItem::MenuItem(const char* name) {
		setEmpty();
		if (name) {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	};
	bool MenuItem::isEmpty() const{
		return m_name == nullptr;
	}

	//set empty state menu class
	void Menu::setEmpty() {
		m_title = nullptr;
		m_index = 0;
		m_indent = 0;
	};

	//menu class constructor
	Menu::Menu(const char* title, int no) {
		if (title) {
			if (strlen(title) < 50) {
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
			}
			else {
				m_title = new char[51];
				for (int i = 0; i < 50; i++) {
					m_title[i] = title[i];
				}
				m_title[50] = '\0';
			}
			m_indent = no;
			m_index = 0;
		}
		else {
			setEmpty();
		}
	};
	//query 
	bool Menu::isEmpty() const{
		return m_title == nullptr;
	}
	Menu::operator bool() {
		return !isEmpty();
	}

	//display method
	ostream& Menu::display(ostream& ostr) const{
		if (!isEmpty()) {
			if (m_indent != 0) {
				ostr << std::setw(m_indent * 4);
				ostr.setf(ios::right);
				ostr << setfill(' ');
				ostr << " ";
			}
			ostr << m_title << "\n";
			if (!m_menu[0].isEmpty()) {
				for (int i = 0; i < m_index; i++) {
					if (m_indent != 0) {
						ostr << std::setw(m_indent * 4);
						ostr.setf(ios::right);
						ostr << setfill(' ');
						ostr << " ";
					}
					ostr << i + 1 << "- ";
					m_menu[i].display(); 
				}
				if (m_indent != 0) {
					ostr << std::setw(m_indent * 4);
					ostr.setf(ios::right);
					ostr << setfill(' ');
					ostr << " ";
				}
				ostr << "> ";
			}
			else {
				ostr << "No Items to display!" << "\n";
			}
		}
		else {
			ostr << "Invalid Menu!" << "\n";
		}
		return ostr;
	}
	void Menu::clear() {
		for (int i = 0; i < m_index; i++) {
			delete[] m_menu[i].m_name;
			m_menu[i].m_name = nullptr;
		}
		m_index = 0;
	}
	int Menu::run()const {
		 display();
		
			int result = 0;
			int exit = 1;
		if(!m_menu[0].isEmpty()&& !isEmpty()){
			while (exit != 0){
				cin >> result;

				if (!cin){
					std::cout << "Invalid Integer, try again: ";
					while (getchar() != '\n');
					std::cin.clear();
				}
				else{
					if (result > 0 && result <= m_index){
						exit = 0;
						while (getchar() != '\n');
						std::cin.clear();
					}
					else{
						std::cout << "Invalid selection, try again: ";
						while (getchar() != '\n');
						std::cin.clear();
					}

				}
			}
			
		}
		return result;
	}
	void Menu::add(const char* text) {
		if (text) {
			if (m_index <= MAX_NO_OF_ITEMS) {
				if (strlen(text) < 50) {
					m_menu[m_index].m_name = new char[strlen(text) + 1];
					strcpy(m_menu[m_index].m_name, text);
				}
				else {
					m_menu[m_index].m_name = new char[51];
					for (int i = 0; i < 50; i++) {
						m_menu[m_index].m_name[i] = text[i];
					}
					m_menu[m_index].m_name[50] = '\0';
				}
				/*m_menu[m_index].m_name = new char[strlen(text)+1];
				strcpy(m_menu[m_index].m_name, text);
				m_menu[m_index].m_name[51] = '\0';*/
				m_index++;
			}
		}
		else {
			delete []m_title;
			m_title = nullptr;
		}
	}
		
	Menu::operator int()const {
		int i = run();
		return i;
	}
	void Menu::operator=(const char* text) {
		if (text) {
			delete[] m_title;
			m_title = nullptr;
			if (strlen(text) < 50) {
				m_title = new char[strlen(text) + 1];
				strcpy(m_title, text);
			}
			else {
				m_title = new char[51];
				for (int i = 0; i < 50; i++) {
					m_title[i] = text[i];
				}
				m_title[50] = '\0';
			}
			
		}
	}

	Menu& Menu::operator<<(const char* text) {
		add(text);
		return *this;
	}
	Menu::~Menu(){
		for (int i = 0; i < m_index; i++)
		{
			delete[] m_menu[i].m_name;
			m_menu[i].m_name = nullptr;
		}
		delete[] m_title;
		m_title = nullptr;
	}
	MenuItem::~MenuItem() {
		delete[] m_name;
		m_name = nullptr;
	}
};