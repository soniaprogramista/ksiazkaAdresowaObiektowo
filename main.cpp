#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
    
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.wypiszWszystkichAdresatow();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.dodawanieAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();


    return 0;
    
}
