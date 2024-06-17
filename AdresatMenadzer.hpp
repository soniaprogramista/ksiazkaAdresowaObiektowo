#ifndef AdresatMenadzer_hpp
#define AdresatMenadzer_hpp
#include "Adresat.hpp"
#include <stdio.h>
#include "PlikZAdresatami.hpp"

class AdresatMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    PlikZAdresatami plikZAdresatami;
    int pobierzIdNowegoAdresata();
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();

public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami) , ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();

};

#endif

