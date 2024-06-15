#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    //idZalogowanegoUzytkownika = ksiazkaAdresowa.wylogowanieUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.dodawanieAdresata();
    ksiazkaAdresowa.wypiszWszystkichAdresatow();

    return 0;
    
}
