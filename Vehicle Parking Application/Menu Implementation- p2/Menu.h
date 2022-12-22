/*
*****************************************************************************
						  Milestone 2
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
#define MAX_NO_OF_ITEMS 10

namespace sdds {
	class Menu;
	class MenuItem {
		friend class Menu;
		char* m_name;
		std::ostream& display(std::ostream& ostr = std::cout)const;
		MenuItem(MenuItem&) = delete;
		void operator=(MenuItem&) = delete;
		MenuItem(const char* name);
		MenuItem();
		void setEmpty();
		bool isEmpty()const;
		~MenuItem();
	};


	class Menu {
		char* m_title = nullptr;
		MenuItem m_menu[MAX_NO_OF_ITEMS];
		int m_indent = 0;
		int m_index = 0;
		void setEmpty();
		Menu(Menu& name) = delete;
	public:
		void clear();
		Menu() = default;
		Menu(const char* title, int no = 0);
		bool isEmpty()const;
		std::ostream& display(std::ostream& ostr = std::cout)const;
		int run()const;
		void add(const char* text);
		operator bool();
		operator int()const;
		void setIndent(int no);
		void operator=(const char* text);
		Menu& operator<<(const char* text);
		~Menu();
	};
}
#endif 