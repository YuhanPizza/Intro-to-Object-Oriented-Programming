/*
*****************************************************************************
						  Workshop - #2 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Assessment.h"
using namespace std;

namespace sdds{
	bool read(int& value, FILE* fptr) {

	return fscanf(fptr, "%d,", &value) == 1;
	}
	bool read(double& value, FILE* fptr) {

		return fscanf(fptr, "%lf,", &value) == 1;
	}
	bool read(char* value, FILE* fptr) {

		return fscanf(fptr, "%60[^\n]\n", value ) == 1;
	}

	bool read(Assessment& asmnt, FILE* fptr) {
		int temp = 0;
		int i = 0;
		fscanf(fptr, "%d", &temp);
		asmnt = *new Assessment[temp];
		do {
			asmnt.m_title = new char[60];
			fscanf(fptr, "%lf, %60[^\n]\n", asmnt.m_mark, asmnt.m_title);
			i++;
		} while (!feof(fptr));
		if (i != temp) {
			return false;
		}
		return true;
	}
	void freeMem(Assessment*& aptr, int size) {

		for (int i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			aptr[i].m_mark = nullptr;
			delete[]aptr[i].m_title;
			aptr[i].m_title = nullptr;
		}
		delete[]aptr->m_title;
		aptr->m_title = nullptr;
		delete aptr->m_mark;
		aptr->m_mark = nullptr;
		delete[]aptr;
		aptr = nullptr;
	}
	int read(Assessment*& aptr, FILE* fptr) {
		int pVal = 0;
		int i = 0;
		 fscanf(fptr, "%d", &pVal);
		aptr = new Assessment[pVal];
		do {
			aptr[i].m_mark = new double;
			aptr[i].m_title = new char[60];
			fscanf(fptr, "%lf, %60[^\n]\n", aptr[i].m_mark, aptr[i].m_title);
				i++;
		} while (!feof(fptr));

		if (i != pVal) {
			freeMem(aptr, i);
			return 0;
		}
		
		return pVal;
	}

}