/*
*****************************************************************************
                          Workshop - #9
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include<string.h>

using namespace std;

namespace sdds{
    //copy constructor for HtmlText       //calls base class copy constructor
  HtmlText::HtmlText(const HtmlText& src) : Text(src){
      m_title = new char[strlen(src.m_title) + 1]; //allocating memory 
      strcpy(m_title, src.m_title); //copying 
  }
  //constructor        char parameter
  HtmlText::HtmlText(const char* title){
      if (title){ //if title has value 
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
      }
  }
  //destructor
  HtmlText::~HtmlText(){
     delete[] m_title; //deallocates memory 
  }

  //ostream object 
  void HtmlText::write(ostream& ostr) const{
    ostr << "<html><head><title>";
    m_title ? ostr << m_title : ostr << "No Title";
    ostr << "</title></head>\n<body>\n";
    m_title ? ostr << "<h1>" << m_title << "</h1>\n" : ostr << "No Title";
    int i = 0;
    while ( Text::operator[](i)) {
        if (Text::operator[](i) == '\n'){
           ostr << "<br />\n";
        }
        else if (Text::operator[](i) == '<'){
           ostr << "&lt;";

        }
        else if (Text::operator[](i) == '>'){
           ostr << "&gt;";

        }
        else if (Text::operator[](i) == ' ' ){
           ostr << " ";
           while (Text::operator[](i+1) == ' '){
             ostr << "&nbsp;";
                    i++;
           }
        }
        else{
            ostr << Text::operator[](i);
        }
        i++;
    }
    ostr << "</body>\n</html>";
  }

  //assignment operator
  HtmlText& HtmlText::operator=(const HtmlText& org){
      if (this != &org){ //if not copying or assigning itself
          Text::operator=(org); //calls assignment operator of base class
          if (org.m_title){ //if title is not null
              m_title = new char[strlen(org.m_title) + 1]; 
              strcpy(m_title, org.m_title);//assigns the title
          }
      }
      return *this;
  }
}