#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika;
    
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    
    return 0;
    
}
