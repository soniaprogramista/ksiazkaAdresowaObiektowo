#include "KsiazkaAdresowa.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
    adresatMenadzer.wypiszWszystkichAdresatow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikMenadzer.logowanieUzytkownika();
    adresatMenadzer.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
}

int KsiazkaAdresowa::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikMenadzer.wylogowanieUzytkownika();
    return idZalogowanegoUzytkownika;
}
void KsiazkaAdresowa::dodawanieAdresata()
{
    vector <Adresat> adresaci;
    adresaci = plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    idOstatniegoAdresata =  plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();
    adresatMenadzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
}
