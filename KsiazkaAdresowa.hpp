#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
using namespace std;
#include "UzytkownikMenadzer.hpp"
#include "AdresatMenadzer.hpp"

class KsiazkaAdresowa
{
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer *adresatMenadzer;
    int idZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {       
        adresatMenadzer = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodawanieAdresata();
    void wypiszWszystkichAdresatow();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void usunAdresata();
    void edytujAdresata();


    bool czyUzytkownikJestZalogowany();

};

#endif
