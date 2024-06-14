#ifndef AdresatMenadzer_hpp
#define AdresatMenadzer_hpp
#include "Adresat.hpp"
#include <stdio.h>
#include "PlikZAdresatami.hpp"

class AdresatMenadzer
{
    PlikZAdresatami plikZAdresatami;
    
    
public:
    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
};


#endif

