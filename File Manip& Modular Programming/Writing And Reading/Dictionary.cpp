/*
*****************************************************************************
						  Workshop - #1 (P2)
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
#include "dictionary.h"


using namespace std;

namespace sdds {

	struct word words[MAX_WORDS] = { };

	int LoadDictionary(const char* filename) {
		//ResetDictionary(&words[100]);
		//word words[100] = { {0} };
		FILE* fp;
		fp = fopen(filename, "r");
		int pVal = fp == nullptr;
		int value = 0;

		if (!pVal) {
			int i = 0;
			char c;
			int j;
			do {
				value = fscanf(fp, "%s", words[i].word);
				fgetc(fp);
				if (value > 0) {
					c = fgetc(fp);
					j = 0;
					while (c == '\t') {
						fscanf(fp, "%[^:]: %[^\n]", words[i].define[j].type, words[i].define[j].description);
						fgetc(fp);
						j++;
						c = fgetc(fp);
					}
				}
				i++;
			} while (!feof(fp));
			fclose(fp);
			return pVal;
		}
		for (int i = 0; i < MAX_DEFINE; i++) {
			strcpy(words[i].word, "");
			for (int j = 0; j < MAX_DEFINE; j++) {
				strcpy(words[i].define[j].type, "\0");
				strcpy(words[i].define[j].description, "\0");
			}
		}
		return pVal;
	}


	void SaveDictionary(const char* filename) {
		FILE* fileptr = fopen(filename, "w");
		int words1 = 1;
		for (int i = 0; words1 > 0; i++) {
			words1 = strcmp(words[i].word, "");
			if (words1 > 0) {
				fprintf(fileptr, "%s\n", words[i].word);
			}
			int description1 = 1;
			for (int j = 0; description1 > 0; j++) {
				description1 = strcmp(words[i].define[j].type, "");
				if (description1 > 0) {
					fprintf(fileptr, "\t%s: %s\n", words[i].define[j].type, words[i].define[j].description);
				}
			}
			fprintf(fileptr, "\n");
		}
		fclose(fileptr);
	}



	void DisplayWord(const char* word) {
		int pNum = 0;
		int wNum = 0;
		int k = 1;
		for (int i = 0; i < MAX_DEFINE && k != 0; i++) {
			k = strcmp(word, words[i].word);
			wNum++;
			if (k == 0) {
				int flag = 1;
				for (int j = 0; flag != 0; j++) {
					pNum++;
					flag = strcmp(words[i].define[j].type, "");
				}
			}
		}
		if (k == 0) {
			cout << "FOUND: [" << words[wNum - 1].word << "] has [" << pNum - 1 << "] definitions:" << endl;
			for (int j = 0; j < pNum - 1; j++) {
				cout << j + 1 << ". {" << words[wNum - 1].define[j].type << "} " << words[wNum - 1].define[j].description << "\n";
			}

		}
		else {
			cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
		}
	}


	void AddWord(const char* word, const char* type, const char* definition) {
		int k = 1;
		int m = 1;
		int empty = 1;
		for (int i = 0; k != 0 && empty != 0; i++) {
			k = strcmp(words[i].word, word);
			if (k == 0) {
				for (int j = 0; m != 0; j++) {
					m = strcmp(words[i].define[j].type, "");
					if (m == 0) {
						strcpy(words[i].define[j].type, type);
						strcpy(words[i].define[j].description, definition);
					}
				}
			}
			empty = strcmp(words[i].word, "");
			if (empty == 0) {
				strcpy(words[i].word, word);
				strcpy(words[i].define[0].type, type);
				strcpy(words[i].define[0].description, definition);
			}
		}
	}


	int UpdateDefinition(const char* word, const char* type, const char* definition) {
		int k = 1;
		int j = 0;
		int number = 0;
		int wPointer = 0;
		for (int i = 0; k != 0; i++) {
			k = strcmp(words[i].word, word);
			wPointer++;
			if (k == 0) {
				int w = 1;
				do {
					w = strcmp(words[i].define[j].type, "");
					j++;
				} while (w != 0);
			}
		}
		cout << "The word [" << words[wPointer - 1].word << "] has multiple definitions:" << "\n";
		for (int m = 0; m < j - 1; m++) {
			cout << m + 1 << ". {" << words[wPointer - 1].define[m].type << "} " << words[wPointer - 1].define[m].description << endl;
		}
		cout << "Which one to update? ";
		cin >> number;
		strcpy(words[wPointer - 1].define[number - 1].type, type);
		strcpy(words[wPointer - 1].define[number - 1].description, definition);
		return 0;
	}
}