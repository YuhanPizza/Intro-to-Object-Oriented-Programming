#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "word.h"

namespace sdds {
    int strLen(const char* s)
    {
        int length = 0;
        while (s[length])
        {
            length++;
        }

        return length;
    }

    void strCpy(char* des, const char* src)
    {
        int i = 0;

        while (src[i])
        {
            des[i] = src[i];
            i++;
        }

        des[i] = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;

        if (strLen(src) >= len)
        {
            while (i < len)
            {
                des[i] = src[i];
                i++;
            }
        }
        else
        {
            while (i < strLen(src))
            {
                des[i] = src[i];
                i++;
            }

        }
        des[i] = '\0';
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, result = 0;
        bool flag = false;

        while (!flag)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                result = s1[i] - s2[i];
                flag = true;
            }

            i++;
        }

        return result;
    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0, result = 0;
        bool flag = false;


        while (i < len && !flag)
        {
            if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
            {
                result = s1[i] - s2[i];
                flag = true;
            }

            i++;
        }

        return result;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        int i = 0;
        const char* result = nullptr;
        bool flag = false;

        while (str1[i] && strLen(str1) > strLen(str2) && !flag)
        {
            if (strnCmp(&str1[i], str2, strLen(str2)) == 0)
            {
                result = &str1[i];
                flag = true;
            }
            i++;
        }

        return result;
    }

    void strCat(char* des, const char* src)
    {
        int des_len = strLen(des);
        int counter = 0;

        while (src[counter])
        {
            des[des_len] = src[counter];
            des_len++;
            counter++;
        }

        des[des_len] = '\0';
    }
  /*  void ResetDictionary(struct word* words) {
        for (int i = 0; i < MAX_DEFINE; i++) {
            strcpy(words[i].word, "");
            for (int j = 0; j < MAX_DEFINE; j++) {
                strcpy(words[i].define[j].type, "\0");
                strcpy(words[i].define[j].description, "\0");
            }
        }
    }*/
}