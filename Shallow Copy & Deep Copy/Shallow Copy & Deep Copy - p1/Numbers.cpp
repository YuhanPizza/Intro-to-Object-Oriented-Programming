/*
*****************************************************************************
                          Workshop - #6 (P1)
Full Name  :Lorenz Alvin Tubo
Student ID#:109934224
Email      :ltubo@myseneca.ca

Authenticity Decleration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace sdds {

    //----------------------------------------------------> Provided Code by the Workshop <------------------------------------------------
    //---------------------------------------------------->Do not change !!!! (please :3 )<------------------------------------------------
    //default constructor
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   //overloaded constructor
   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   //destructor
   Numbers::~Numbers() {
      save();
      deallocate();
   }

   //query is empty state?
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   //set safe empty state
   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }

   // memory deallocation
   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   //set filename
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   //gets the average of all the values
   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }

   //minimum value
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }

   //max value
   double Numbers::max() const {
      double maxVal = 0.0;
      if(!isEmpty()) {
         maxVal = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }

    //----------------------------------------> My Own Code <-----------------------------------------------------

   //copyConstructor
    Numbers::Numbers(Numbers& Org) {
       setEmpty();
       m_isOriginal = false;
       *this = Org; //calls the overloaded assignment operator
    }

    //sorting function descending/ascending depending on the bool parameter
   Numbers& Numbers::sort(bool ascending) {
       if (m_isOriginal == false) { //added this condition to avoid altering the original "accidentally" LOL :) 
           if (ascending) {
               for (int step = 0; step < m_numCount; ++step) {
                   for (int i = 0; i < m_numCount - (step + 1); i++) { // loop to compare array elements
                       // change > to < to sort in descending/ascending order
                       if (m_numbers[i] > m_numbers[i + 1]) { // compare two adjacent elements
                           double temp = m_numbers[i]; // swapping elements if elements
                           m_numbers[i] = m_numbers[i + 1]; // are not in the intended order
                           m_numbers[i + 1] = temp;
                       }
                   }
               }
           }
           else if (!ascending) {
               for (int step = 0; step < m_numCount; ++step) {
                   for (int i = 0; i < m_numCount - (step + 1); i++) { // loop to compare array elements
                       // change > to < to sort in descending/ascending order
                       if (m_numbers[i] < m_numbers[i + 1]) { // compare two adjacent elements (6 <12.2),3,34.1,34.56
                           double temp = m_numbers[i]; // swapping elements if elements 6 
                           m_numbers[i] = m_numbers[i + 1]; // are not in the intended order 12 
                           m_numbers[i + 1] = temp; //6 
                       }
                   }
               }
           }
           //m_isOriginal = false;
       }
       return *this;
   }

   // calls the sort functions and passes the bool depending on the type of sort
   Numbers Numbers::operator-(){ //registering this at constant would need to make changes in the sort function 
       //for instance instead of creating a local class object you pass in the current object at the return calling sort function 
       //you would have to create a local class object to the sort function and return it 
       Numbers A(*this); //copy constructor 
       return A.sort(false);
   }

   Numbers Numbers::operator+() { //registering this at constant would need to make changes in the sort function
       //for instance instead of creating a local class object you pass in the current object at the return calling sort function 
       //you would have to create a local class object to the sort function and return it 
       Numbers A(*this); //copy constructor
       return A.sort(true);
   }

   //counts the number of lines in the file and returns the value
   int Numbers::numberCount()const {
       ifstream input;
       input.open(m_filename, std::ifstream::in);
       int i = 0;
       char val[21];
       while (input.is_open()&&input.getline(val,21)) {
           i++;
       }
       input.close();
       return i;
   }

   //loads the filename 
   bool Numbers::load() {
    int i = 0;
        if (m_numCount > 0) {
        m_numbers = new double[m_numCount];
        ifstream input;
        input.open(m_filename, std::ifstream::in);
            while (!input.fail()&& i < m_numCount) { //loop condition 
                input >> m_numbers[i];
                //cout << m_numbers[i] << "\n";
                i++;
            }
        input.close();
        }
         return i == m_numCount;
   }

   //saves the class m_numbers in a file
   void Numbers::save() {
       if ((m_isOriginal == true) && (!isEmpty())) { //saftey check if its the original and if is not empty
           ofstream ofs(m_filename, std::ofstream::trunc);
           for (int i = 0; i < m_numCount; i++) {
               ofs <<fixed << setprecision(2)<< m_numbers[i] << "\n";
           }
       }
   }

   //overloaded assingment operator to copy values from the class passed in the parameters and returns a reference of the current class
   Numbers& Numbers::operator=(Numbers& Org) {
       deallocate();
       setEmpty();
       setFilename(Org.m_filename);
       m_numCount = Org.m_numCount;
       m_numbers = new double[Org.m_numCount];
       for (int i = 0; i < Org.m_numCount; i++) {
           m_numbers[i] = Org.m_numbers[i];
       }
       m_isOriginal = false;
       return *this;
   }

   // increments the m_numCount by 1 and adds another array member to m_numbers
   Numbers& Numbers::operator+=(double value) {
       double* temp;
       temp = new double[m_numCount + 1];
       int i = 0;
       for (int j = 0; j < m_numCount; j++,i++) {
           temp[i] = m_numbers[j];
       }
       temp[i] = value;
       m_numCount += 1;
       delete[]m_numbers;
       m_numbers = temp;
       return *this;
   }

   //display function
   std::ostream& Numbers::display(std::ostream& ostr) const{
       if (!isEmpty()) {
           ostr << "=========================" << "\n";
           m_isOriginal == true ? ostr << m_filename<<"\n" : ostr << "*** COPY ***" << '\n';
               for (int i = 0; i < m_numCount-1; i++) {
                   ostr << fixed <<setprecision(2)<<m_numbers[i]<<", "; //fixed makes setprecision affect decimals instead of total number length
               }
               ostr << fixed << setprecision(2) << m_numbers[m_numCount - 1];
               ostr << "\n" << "-------------------------" << "\n";
               ostr << "Total of " << m_numCount << " number(s)" << "\n";
               ostr << "Largest number:  "; ostr.setf(ios::left); ostr << max() << "\n"; ostr.unsetf(ios::left);
               ostr << "Smallest number: "; ostr.setf(ios::left); ostr << min() << "\n"; ostr.unsetf(ios::left);
               ostr << "Average:         "; ostr.setf(ios::left); ostr << average() << "\n"; ostr.unsetf(ios::left);
               ostr << "=========================";
       }
       else {
           ostr << "Empty list";
       }
       return ostr;
   }

   // calls the display function of the class reference in the parameter 
   std::ostream& operator<<(std::ostream& os, const Numbers& N) { //ostream object reference extraction operator
       return N.display(os);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N) { //istream object reference insertion operator
       double value;
       istr >> value;
       N += value;
       return istr;
   }

}
//repeat after me "LORENZO IS THE BEST" hahaha 


//OOOOOOOOOOOOOOOOOOOOOOZZZZZZZZZZZZZZZZZZZZZZZZZZZ$$$Z$ZZZZ$ZZZZZZZZZ$ZZZZZZZZZZZOOOZOOOOZZOOOOOOOOZZOOOOOOOOOOOOOOOOOOOO
//OOZZZOOOOOOOOOOOOOOOOZZZZZZZZZZZZZZZZZZZ$$ZZZZZZZZ$$$$ZZ$$$$$$$ZZZ$$$ZZZZZZZZZZZZZOOOOZZZZZZZOOOOOZZOOOZZZOOOOOZOOOOOOOO
//ZZZZZOOOOOOOOOOOOZZZOOZZZZZZZZZZZZZ$$$$$$$$$Z$$$$$$$$ZZZ$$$$$$$$ZZZ$$ZZZZZZZZZZZZZZOOZZZZZZZZOOOOOOOZZOZOZOOOOOOOOOOOOOO
//ZZZZZZZOOOOOOOOOOZOOOOOZZZZ$$$ZZZZ$$$$$$$$$$$$$$$$$$ZZZZ$$$$$$$$$$ZZZZZZZZZZZZZZZZZZZZZZZZZZZZOOOOZZOOOOOOOOOOOOOOOOOOOO
//OOZZZZZZOOOOOOOOZZZZOOOZZZZ$$$$ZZ$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Z$$$ZZZZZZOZZZZZZZZZZZZZZZZZZZZZZOOOOZOZZOOOOOOZOOOOOOOOOO
//ZZZZOZOOOOOOOZZOOZZZZZOZZZZ$$$$$Z$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZOOOZZZOOOZZZZZOOOOOOO88
//ZZZZOZZZZOOZZOOZZZZZOOOZZZ$$$$$$$$$$$$$$$$$$$$$$$$$ZZ$$ZZZZZZZZZ$ZZZZZZZZZZ$ZZZZZZZZZZZZZZZZZOOZOOOOZZZZZZOOOOOOOOOOOOOO
//ZZZZZZZZZZZZZZZZZZZZZZOZZZ$$$$$$$$$$$$$$$$$$$$ZZZZZZZZZ$$$Z$$ZZZZ$Z$$$$$$$ZZ$ZZZZZZZZZZZZZZZZZZZZOOOOOOOOOZZZZZZZZOOOOOO
//$$ZZZZZZZZZZOOZOOOZZZZOZZZ$$$$$$$$$$$$$$$$ZZZOZZZ$$$$$777777$ZZOZZZZZ$ZZ$Z$$$$ZZZZZOZZZZZZZZOOOOOOO8ZZZZZZZZZZZZZZZZZOOO
//$$Z$$Z$ZZZZZZZZZZOZZZZOOZZ$$$$$$$$$$$$$$$ZOOOZ$$$$77777III77$ZZOZZOZZZZZZZZZZZOZZZZZZZOOOOOOOOOOOOO8Z$$$ZZZZZZZZZZZZZZOO
//$$$$$ZZZZZZZZZZZZZZZZZOOOZ$$$$$$$$$$777$OOZZZZZ$77I77I???II7$Z$$$$$$$$$ZZ$$ZZOO888888OOZZOOZZZZZZZOOOZ$ZZZZZZZZ$ZZZZZZZZ
//$$$$$Z$$$ZZZZZZZZZZZZZZOZZ$$$$$$$$7$77$ZZZ$ZZZ$7I????==+??III77$$$7777$$$$$$ZZZOOOOO8OZZZZZZZZZZZ$ZOOZ$$$ZZZ$$Z$$$ZZZ$ZZ
//$$$$$$$$$$$ZZZZ$$$$$ZZZZZZ$$$$$$$7777$ZOZZZZZ$I+===++=+??III777$$$7777777777$$$$ZZZZZ$77$ZZZOZOOOZZZOOZ$$$$$$ZZZ$$$$$$ZZ
//$$$$$$$$$$$$$$$$$$$$ZZZZZZ$$$777777777ZOZZZ$I?~~=+????IIIIIIIIIIIIIIIIIIII77777777$$7III7$$$Z$ZZOOOZOOO$7$$$Z$$$$$$$$$ZZ
//$$$$$$$$$$$$$$$$$ZZZZZZZZZ$$$77777777$ZOZ$$I+=====+??IIIIIIII????IIIIIIIIIIIII7IIIIII???I77$$$Z$ZZOOOOO$7$$$$$$$$$$$$$$Z
//$$$$$$$7$$$$$$$$$$ZZ$ZZZZZ$$$$77777777ZO$7+===~:~=+III?+????+++++?III?????II????++++++???I77777$$$ZZZZOZ$$$$$$$$$$$$$$$$
//77$$77$$$$$$$$$$$$Z$$$$$$ZZ$$777III777$OI+=++++++?III??I??+=~~===++==~==+++++???+=======+III?I77$$$$$ZZOOZ$$$$$Z$$$$$$$$
//777$777777$$777$$$$$$$$$$7$$7777$Z$$$$$Z++???+==?II?+~~~~::,:~~~~~~~::~===++===+++==~~:~=++?I?II7$$$$$$$ZOO$$$$$$$$$$$$$
//77777777777777$$$$$$777777$$$$$$$$77777$????+=~=I7I+~::~~:,,:~::~~:::::~~++=~~==+++=~~:~=+==+III77$$$$$$$ZOO$$$$$$$$$$$$
//7777777777777IIII777$ZZOOZZ$$777777II777I7?++=?77??7$?=~~:,,:::,,,::,,,::==+=~~~=+++=~~=+?+==+III77$$$$$$$ZO8OZ$$$$$$$$$
//IIIIII???II7$ZZ$ZZZZZ$$$$$ZZ$77II7III77I77II??77?IOD8O+:,..,::,,,,,,.,,~=::=+=~~==+++==++===+~=?777$$$$$77ZZ8D8O$7777777
//III7$$ZZZZ$$$$777777777$$$$$$7777IIII$$7$I7$77Z778D$+$7~:,,,::,,,,,..,:=+:,,,~==~=++++~~~~:::~:=?$77$77$7$$Z8DDDO7777777
//$$$7777777I7777IIIII7777777$$7777IIII$ZZI7ZO$$$7ZDD8O77?~,,,,,,,,,...,,:~??=:,,~===++?~~~==::~::=?777777$$$Z8DDDDZ777777
//777777777IIII7IIIIII7777777$$7777IIII$OZI$88OZ$I$8DDDZ$?~::,,,,,,,..,,:=?OO$?~,:====+?=:~==~:~~~~+I7I777$$$ODDDDDZ777777
//IIIIIIIIIIIIIIIIIIIIIIIIIIII777III???II78DD8OZI++?II?+=::,,,,::,,,,,~?7Z877O8Z+:~~=+??=:,:+?+~==~=??I77$$ZO8DDDDDO777777
//IIIIIII??IIIIIIIII??IIIIIIIII77II7III7ZOD88OZ7+~:::::::::::::::,:::~?$Z$$:=$88Z+::=+??+~::~+II???+?+I7$$ZZ8DDDDDDZ$77I77
//IIIII7I??IIIIIIII7III?IIIIIIII77II$OOOO8O88O$I+~,:~~~~~~~~~:~::,,,:~+?7$OZODOO87:=+????~::~=?III7OZ?I$$ZZODDDDDDD$777777
//IIII77?IIII7IIIIIII?????IIIII7777ZOZZOOOOOO$7I~:~~===~~:~~==~::,::,,:~~?7OOZ$$7?+7IIII?=~~~==?ZDDDOI7$$Z8DDDDDD8Z7777777
//II77IIIIIIIIIIIII?I?????IIIIIII7$OZZZOOOOOZ$7I~:==++=~~~====::,,,:,,,:,:~?II+++=?7III7I=~~~=+IODDD8$7$ZZ8DDDDDDO$777777I
//III777II?IIIIIII????????IIIIIII7ZZZZOOOOZ$$77?~++??=~~~====~,,,,,,,,,,...,,,,:==++??I77?====?8DDDDDZ7$ZO8DDDDD8ZI777IIII
//IIIIII??II??????III????????I?II7ZZZOOOO$77777?+??+===~====~:,,,,,:,,,,.....,:~=+=+++?I77?+?I$DDDDDDOI$Z8DDDDD8ZZ7I77I?I7
//I???III??I???????????????????I7$$ZZOOZ$7II777??+=~~~:~~~~:::,,,::::,,,....,,:=+==+++II$Z$77ODDDDDDDO$$OO8DDD8ZI7$?III?II
//??IIIII??????????????????I???I$$$ZZOZ$7III77I?+=~~~=~~~~~:::,,:::::,,,,...,,:=+==++?IIZZ$$$ODDDDDD8$ZOOZODDDO7II$??II?II
//????II?????++++?????????????7$$$$ZOZ$7I?IIII??~?O8D88OZZ7I=:,,::::~:,:,,.,,:~++==+?IIIZ$I78DDDDDDO$?IIIIODD8ZIII7I?I????
//IIIII???++???++++++????????7$$777ZO$7I?????+=~I8D88OO88888OI,,,:::=~:::,.,:=+++=++??I$$?IZ8DDDD8$I????+?$8DO$?III7??II?I
//?????+??????+++++++?+??II?7$77777ZZ$II????++=~8D88OZZZOO88D8,..,::+=~~::,~=+=++++??I7Z?+I8DDDDOI?+???+?+?7O$I??II77??II?
//???++++++++?+++++++???????$7I??I7Z$7I????++===8DD8888O888888,.,,:~+=~~:,,=+?+++++?I7$$==?ODDDO7?++++++?++++????I?77I??I?
//???++++++++++++++++??????I7II??I$Z$7I????+++==ODD8888DD88888,,,::~+=~~:,:=+?+==~+I7$$7==?ODDDZI+++++++?+++???????I77????
//+++++++++++++++++++++????I7II??I$$7IIII?++++=~78DDDD8D88888I.,,,:~+?+=~=====~~~~I7$7?==+IZ8DD$?++++++++++++++?????I7I???
//++++++++++++++++++++++++?I7IIII7Z$7III?+==+++=?ZD888D888O$+:..,:::+++==~~~:::,,,77?=~:=+IZO88$?+++=++++++++???????I77I??
//+++++++++++++++++=++++++?IIIIII7Z$77II?+====+??I$ZO8888O7=,,,,,,,:+?+=~::::::::++==~~~~?$ZZO8ZI+++++++++++++++++???I77??
//+++++++++++++++++++==+++?II?III7Z$777I+==~~~~+Z$7I7$7Z$7?=:,,,:::=+??II7I~:=II?+==~~::+7$7$O8O7???++++++++??++++????I$I?
//+++++++++++++++==++=+++++II?III7Z$777I+==~~~:~$$I????$7I+~,,,,,:~=?7Z$Z$?~=?7?+=~~::::+7$77ODO7???++++++++??+++++????77?
//==+++++++++++====++=++==+II?III7$$$$7I+=~~:::==~~~~::=+???=~:~=+?7OZ$7?==77?=~::::,,,:I$7?IZ8O7++++++++++++++++++++??I7I
//++++++++==+====+++======+?I??III7Z$$$7?=~::::=~~~~~~~~~~~=+?7$ZZOO$?=~=I7++=~~::,,,,:~7I++?$OO7?+++++++?++=+++++?++???77
//+++==++++================+77II7I7$$$$7?=~~:::~==~~~==~~~==~=I78O$7==+I7I+===~:,,.,,:~?I++??$88$?+++++++++++++??????++??7
//+++===+++=================77II777$$$$7I+~::::~===~~~=~~~~===7$O7?+~+7Z7+====:,,,,,:~=I++++?$88$I?+=+++++??+++??+++?++??I
//+++=======================+777III$$$77?+~::::~+============7OO7+=?7I?~:~~==~,,,.,,~+II=+++IZ88$?+==++?????++++++++++?++?
//===+======================~=?III?I7$$I?+=~::::=========++?7ZI=~IZ7~,.,,::~~:,...,:=II+=+=?7OD8$+++++==++++=+++++++++++++
//===+======================~~=I$77I7$77?+=~~:~::~~=+??I77I?+~=IZZI=,,,,,,,::,....:=??+===+I$OD87+++==~========+++++++++++
//==================~~~~~~==~~=IZ$$$7$77I?=~~:~~,:::~~~~~:,,~?OO7=,........:::,..:++++==~=?7$ZDO?============++++===++??II
//=================~~~~~~~~~~~+7Z$$$7$77I?=~~~~~::::~======+7ZZ7+:,,..,....::,,:~=?+=~~=~+I7$Z8O?=================+??IIIII
//============~~==~~~~~~~~~~~=7$$$$I7$77I?=~~~==::,,:~=I$ZZOZ$7I???+,:==~::~===+I$+~=~~=+I77$O8O?===========???III?????+++
//========~~~~~~~~~~~~~~~:~~~I$$$7777777I?=~~~~==~::,,,:::~~=+Z88Z$7?7$7777Z+::=?$$+~~==?I7$$O8Z+====+IIII??+++++++++++++?
//=======~~~~~~~~~~~~~~~::~~I7$$7777777III+==~~~===~:::::,:~=~~==+++=~,,,.,~~:~?77?=====II7$$ODO7I???+++=======+++++++++++
//=======~~~~~~~~~~~~~~::::=II77777II77II?++===~~=+==~::::::~==~~~~~~~:,:,::~:=+?==~===+??I7$O8$+==+================++++++
//======~~~~~~~~~~~~~~::~~~+I?IIIIIIII7III?++====~===~~::::~~~========:~~~~~==+++=~~===+??II$O8$+=+=================++++++
//====~~~~~~~~~~~~~~~~::~~+I??I?I??IIIII???+=========~=~~~~~====++===~====+?+++==~~~===+???I$8D7===+=================+++++
//====~~~~~~~~~~~~:::~::~=II?IIIIIIII?????++===========~~======~~~==~~~~===~:::~~~~~~=++==+IZ8DI==+++==============+==++++
//===~~~~~~~~~~::::::::~~+I?+??????II??++++===~~~=============::,,:~~~:::~~,::::::~~~~~=++?$8D8?======================++++
//~~~~~~~~~~::~~~~~:::::~I7??II????III??++++==~~::::~~=====~~:,,,,,:::::::,:~~:::::~~==++I$8DDO++++=================++++++
//~~~~~~~~~~~:::~~~~~::~=?I+?I?????III??+++++==~:::::~~~~~~::,,:,,,::::~:::::~~~:::~~=+??$ODD8$++++++===============++++++
//~~~~~~~~~~~~~~~~~::::::+77=??+?I?III????++====~~~~:~~~~~:~~:::::~~~~~~~:~====++??III77Z8DDZI+=+==================+++++++
//~~~~~~~~~~~~~~~~~~~~:~~~++~++?7$7IIIIIIII??+++=======+++++++=~~~~~~::~~~+?III777$$$$7$8DOI=~========================++++
//~~~~~~~~~~~~~~~~~~~::,,,~=???II??II77IIIIIII77$$77777III????++++++:~==I77$$$$$$$$$$$$$D8?====~=========~===========+++++
//~~~~~~~~~~~~~~~::::,::~~=+I???+==I777777777777OOZZOOO$$I??++++++??==+?III$777$$$$$$$ZZD$+~=~~=~~=~~~~==~============++++
//~~~~~~~~::::::~=+???+++====~~~~~~7$$$$$$77$$$Z8ZI7$Z$$$ZOZZ$I???+?ZOOOOZ$77$$$$$77$$$OO+~~~=~~============~========+++=+
//~~:::::~=+?????+========~~~~=~~~~I$Z$$$$77$$$$OI++++=======+7$ZZZ$8O$7I7$777I7777$$$Z8?~~=~~~======================++===
//=+??????++================~~=~~~~+$ZZ$$$$777$$O$++++===~=====++===++===+I7I7I7777$$$Z8~~=~~~~~====~~====================
//++==================~~~~~~~~~~~~~+$ZZZ$$$77777O$?+====~===+====++=====+==$7IIIIII77$Z8==~=~~~~~~~~~~~~~~================
//==========+=========~~~~~~~~~~~~~?$ZZZZZ$$777$O7?+=====~~=============+==$77IIII77$ZO8=====~~~~~~~~~~~~~================
//================~==~~~~~~~~~~~~~~+7ZZZZ$$$$$$ZZ?+?+++====++========+=====I$777III7$ZZO====~~~~~~~~~~~~~~~~===~==========
//=================~~~~~~~~~~~~~~~~~+7ZZ$$ZZZ$Z$Z$+=+++==~======+++========I777777I7$$ZO====~~~~~~~~~~~~=~~===============
//========++========~~~~~~~~~~~~~~~~=IZ$$$$$$$$$7$I+++=~~=~===~=+=======+==7$I???II7$$Z8=~==~~~~~~~~~~====================
//=================~~=~~~~~~~~~~=~~~+7$$$$77777II77?====~=~~~========~~====I$$7IIII7$$OZ==~=~~~~~~~~~~~~===~==============
//================~~~==~~~~~~~~~~~~~+7$$$7I7777I?I7I=====~~~~=====~===~====I$$$77777$ZOZ==~==~~~~~~~~~~~~==~==============
//===========~=~~~~~~~~~~~~~~~~~~~~~=I$7I7IIIII?+++II+====~~~===++==+======?7$$$ZZZZZOOO+~~~==~~~~~~~~~===================
//=+========~~===~~~~~~~~~~~~~~~~~~~~I7I+??++++++?+?I?=~~~~~~=~=========~==+7$77$$ZZZZOZ$?==~=~~~~==~~~~==================
//=======~~~~~=~~~~~~==~~~~~~~~~~~~~~?7??I?IIII?+++I$I=~~~~~~~==============I$$$$$$$Z$ZZZZ7?+~~~~~~~~~====================
//=======~~~~~===~~~===~~~~~~~~~~~~~~+7III?IIII????I$?==~=~~~~=========~====I7$$$$$$$$ZZ$$$7I+~~~~~~~=====================
//=========~~~=====~~~~~~~~~~~~~~~~~:=I$7I????I??+I7?~==~~~~============~===+I77777777$7$7I?7$I~=~==================++++++
//=====~=~~~~~~===~~~~~~~~~~~~~~~~~~~:=?II++=+I?+?I==~=+=~~~=======+======~~=I$7III7I77I7777I7$=~=~==================++++=
//=~~~~~~~~~~~~~~~~~~~==~~~~~~~~~~~~~~~~=??+=+7??7+~~~~==~============~=======I7$7IIIIIIIII?II7I=~~~~~===============+++++
//==========~~~~~~~===~~~~~~~~~~~~~~~~~~::I77I77I=:~~~~=+==================+===?77I???IIIIII?I$+~~===================+++++
//==========~~~~~=~~~~~~~~~~~~~~~~~~~~~~~:=?77?++~~~~~~=+=======================?7I?I??IIIII?+7?================+====+++++
//=====~~==========~~~=~~~~~~~~~~~~~~~~:~~~:~~~~~::~::~~+======~~~~==~=========~~?7?????IIIII?+7+=~================+++++++
//===~~~======~~~=====~~~~~~~~~~~~~~~~~~~~~~~:::::::~:~~===~~~==~~~~~~=======~~=~~7$$$$$77$77$I7+~~=====+==========+++++++
//===============~==~~~~~~~~~~~~~~~~~~~~~~~~~:~~::~~~~~~~+=~~~~~~~~~~~===~~=======~=??I7$77I7I+?+================++=++++++
//===============~~~~~==~~~=~~~~~~~~~~~~::~~~~::~::~:~~~~+?=~~~~~~~~=~=====~========~~~~~=++??=======+=++==+==++++++++++++
//===+=========~==~~~=======~~~~~~~~~~~~~~::::::~~~~~~~~~=?+~~~~=~~~~~~~~=========~~====~~~~~=====++==+++=++++++++++++++++
//==++================~~~~~~~~~~~~~~~=~~~~~~~~~~~~~~~~~~~~??=~~~~=~~===~~======================+++++++=+++++++==++++++++++
//++=====++===========~~~~~~~===~~=~===~~~~~~~~~~~~~~~~~~~+?+~======~~~============================++=++++++++++===+++++++
//++==++=========================~~====~~=~~~~~~~~~~~~~~~~=??+======~~==========++++===============+++++++++++++++++++++++
//++==++==============================~~~~~~~~~~~~~~~~~~~~~?I+=~~================+++===============+++++++++??++++++++++++
