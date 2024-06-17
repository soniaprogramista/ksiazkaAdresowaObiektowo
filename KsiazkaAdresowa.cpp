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
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer->wypiszWszystkichAdresatow();
    }
    else
        cout << "Nie jestes zalogowany"<<endl;
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
   idZalogowanegoUzytkownika =  uzytkownikMenadzer.logowanieUzytkownika();
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer = new AdresatMenadzer (NAZWA_PLIKU_Z_ADRESATAMI, idZalogowanegoUzytkownika);
    }
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
    }
    else
        cout << "Nie jestes zalogowany" <<endl;
}

int KsiazkaAdresowa::wylogowanieUzytkownika()
{
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        idZalogowanegoUzytkownika = uzytkownikMenadzer.wylogowanieUzytkownika();
        delete adresatMenadzer;
        adresatMenadzer = NULL;
        return idZalogowanegoUzytkownika;
    }
    else
        cout << "Nie jestes zalogowany" <<endl;
    return 0;
    
}

void KsiazkaAdresowa::dodawanieAdresata()
{
    if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        adresatMenadzer->dodajAdresata();

    }
    else
        cout << "Nie jestes zalogowany" <<endl;
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        return true;
    }
    else
        return false;
}
