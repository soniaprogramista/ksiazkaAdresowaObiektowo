#ifndef PlikTekstowy_hpp
#define PlikTekstowy_hpp
#include <iostream>
#include <stdio.h>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;
    
   public:
    
       PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
       }
    
    string pobierzNazwePliku();
    
    bool czyPlikJestPusty();
      
};




#endif /* PlikTekstowy_hpp */
