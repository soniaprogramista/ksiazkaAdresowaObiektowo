#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
using namespace std;
#include "UzytkownikMenadzer.hpp"

class KsiazkaAdresowa
{
    UzytkownikMenadzer uzytkownikMenadzer;
public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
