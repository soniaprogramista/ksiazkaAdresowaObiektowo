#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    //idZalogowanegoUzytkownika = ksiazkaAdresowa.wylogowanieUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.dodawanieAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
    
}
