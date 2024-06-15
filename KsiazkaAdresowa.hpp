#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
using namespace std;
#include "UzytkownikMenadzer.hpp"
#include "AdresatMenadzer.hpp"

class KsiazkaAdresowa
{
    int idOstatniegoAdresata;
    UzytkownikMenadzer uzytkownikMenadzer;
    int idZalogowanegoUzytkownika;
    AdresatMenadzer adresatMenadzer;
    PlikZAdresatami plikZAdresatami;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenadzer.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void dodawanieAdresata();
    void zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();

};

#endif
