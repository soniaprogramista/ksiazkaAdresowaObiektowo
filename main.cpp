#include <iostream>
#include "KsiazkaAdresowa.hpp"

using namespace std;

int main() {
   
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    
    
    return 0;
}
