#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    //idZalogowanegoUzytkownika = ksiazkaAdresowa.wylogowanieUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.dodawanieAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    return 0;
    
}
