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
    idOstatniegoAdresata = ksiazkaAdresowa.dodawanieAdresata();
   
    
    return 0;
    
}
