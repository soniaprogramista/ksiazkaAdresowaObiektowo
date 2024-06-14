#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp
#include "Adresat.hpp"
#include <stdio.h>

class PlikZAdresatami
{
   string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku(Adresat adresat);
};


#endif
