#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wybierzOpcjeZMenuUzytkownika();
    static char wczytajZnak();
    static char wybierzOpcjeZMenuGlownego();
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();

};

#endif
