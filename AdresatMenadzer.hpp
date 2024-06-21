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
    int podajIdWybranegoAdresata();
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    string nazwaPlikuZAdresatami;


public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami) , ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    int usunAdresata();
    void edytujAdresata();

    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);




};

#endif

