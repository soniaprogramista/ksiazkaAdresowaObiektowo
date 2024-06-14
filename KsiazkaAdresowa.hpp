#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
using namespace std;
#include "UzytkownikMenadzer.hpp"

class KsiazkaAdresowa
{
    UzytkownikMenadzer uzytkownikMenadzer;
public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
