#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H
#include <thread>
#include <iostream>
using namespace std;
#include<fstream>
#include <sstream>
#include "PlikZUzytkownikami.hpp"
#include "Uzytkownik.hpp"

class UzytkownikMenadzer
{
    int idZalogowanegoUzytkownika;
    PlikZUzytkownikami plikZUzytkownikami;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    
public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika =0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
