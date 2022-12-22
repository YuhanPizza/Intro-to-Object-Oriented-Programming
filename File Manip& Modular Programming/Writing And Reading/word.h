#ifndef SDDS_WORD_H
#define SDDS_WORD_H

 

namespace sdds {
    const int MAX_WORDS = 100;
    const int MAX_DEFINE = 8;
    const int MAX_CHAR = 64;
    const int MAX_DEFINITION = 1024;
    struct definition {
        char type[64];
        char description[1024];
    };
    struct word {
        char word[64];
        struct definition define[8];
    };
   //void ResetDictionary(struct word*);
	int strLen(const char* s);
	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);
}

#endif
