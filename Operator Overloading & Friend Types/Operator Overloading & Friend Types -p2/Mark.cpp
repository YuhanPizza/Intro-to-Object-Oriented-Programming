/*
*****************************************************************************
						  Workshop - #5 (P2)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds {
	//constructors
	Mark::Mark() {
		m_mark = 0;
	}
	Mark::Mark(int value) {
			m_mark = value;

	}
	//checker 
	Mark::operator int()const {
		return m_mark;
	}
	Mark::operator bool()const {
		return (m_mark >= 0 && m_mark <= 100);
	}
	Mark::operator char()const {
		char value = 'F';
		if (m_mark >= 50 && m_mark < 60) {
			value = 'D';
		}
		if (m_mark >= 60 && m_mark < 70) {
			value = 'C';
		}
		if (m_mark >= 70 && m_mark < 80) {
			value = 'B';
		}
		if (m_mark >= 80 && m_mark <= 100) {
			value = 'A';
		}
		if (m_mark == -1) {
			value = 'X';
		}
		return value;
	}
	Mark::operator double()const {
		int value = 0;
		if (m_mark >= 50 && m_mark < 60) {
			value = 1;
		}
		if (m_mark >= 60 && m_mark < 70) {
			value = 2;
		}
		if (m_mark >= 70 && m_mark < 80) {
			value = 3;
		}
		if (m_mark >= 80 && m_mark <= 100) {
			value = 4;
		}
		return value;
	}

	bool Mark::operator~() const{
		return (m_mark >= 50);
	}

	bool Mark::operator < (const Mark& M)const {
		if (*this && M) {
			return (m_mark < M.m_mark);
		}
		return false;
	}
	bool Mark::operator > (const Mark& M)const {
		if (*this && M) {
			return (m_mark > M.m_mark);
		}
		return false;
	}
	bool Mark::operator <= (const Mark& M)const {
		if (*this && M) {
			return (m_mark <= M.m_mark);
		}
		return false;
	}
	bool Mark::operator >= (const Mark& M)const {
		if (*this && M) {
			return (m_mark >= M.m_mark);
		}
		return false;
	}
	bool Mark::operator != (const Mark& M)const {
		if (*this && M) {
			return (m_mark != M.m_mark);
		}
		return false;
	}
	bool Mark::operator == (const Mark& M)const {
		if (*this && M) {
			return (m_mark == M.m_mark);
		}
		return false;
	}

	//prefix
	Mark& Mark::operator++() {
		if (*this) {
			++m_mark;
		}
		return *this;
	}
	Mark& Mark::operator--() {
		if (*this) {
			--m_mark;
		}
		return *this;
	}
	//postfix
	Mark Mark::operator++(int) {
		Mark j;
		j.m_mark = m_mark;
		if (*this) {
			m_mark++;
		}
		return j;
	}
	Mark Mark::operator--(int) {
		Mark j;
		j.m_mark = m_mark;
		if (*this) { 
			m_mark--; 
		}
		return j; 
	}

	Mark& Mark::operator=(int value) {
			m_mark = value;
		return *this;
	}

	Mark& Mark::operator+=(int value) {
		if ((*this) && (m_mark + value)<=100) {
			m_mark += value;
		}
		return *this;
	}
	Mark& Mark::operator-=(int value) {
		if ((*this)&& m_mark >= value) {
			m_mark -= value;
		}
		return *this;
	}

	Mark Mark::operator+(int right) const{ 
		Mark j;
			j.m_mark=m_mark + right;
			return j;

	}
	Mark Mark::operator+(const Mark& M)const { 
		Mark j;
			j.m_mark = m_mark + M.m_mark;
			return j;
	}

	Mark& Mark::operator<<(Mark& right) {
		if ((*this && right) && (int(*this) + int(right) < 100)) { 
			m_mark += right.m_mark;
			right.m_mark = 0;
		}//add before returning have conditions to check return value;
		return *this;
	}
	Mark& Mark::operator>>(Mark& right) {
		if ((*this && right) && (int(*this) + int(right) < 100)) {
			right.m_mark +=m_mark ;
			m_mark = 0;
		}
		return *this;
	}
	int operator+(int& value, const Mark& right) {
		int result = value + int(right);

		return result;
	}
	int operator+=(int& value, const Mark& right) {
		return value += int(right);
	}
	int operator-=(int& value, const Mark& right) {
		return value -= int(right);
	}
}
