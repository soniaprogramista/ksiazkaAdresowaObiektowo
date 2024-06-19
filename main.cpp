#include <iostream>
#include "KsiazkaAdresowa.hpp"
#include "MetodyPomocnicze.hpp"

using namespace std;

int main() {
    vector <Adresat> adresaci;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    char wybor;
    
    while (true)
    {
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
            
            switch (wybor)
            {
                case '1':
                    ksiazkaAdresowa.rejestracjaUzytkownika();
                    break;
                case '2':
                    ksiazkaAdresowa.logowanieUzytkownika();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("read -n 1 -s -p\" Press any key to continue...\"");
                    break;
            }
        }
        else
        {
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
            
            switch (wybor)
            {
                case '1':
                    ksiazkaAdresowa.dodawanieAdresata();
                    break;
                case '2':
                    ksiazkaAdresowa.wyszukajPoImieniu();
                    break;
                case '3':
                    ksiazkaAdresowa.wyszukajPoNazwisku();
                    break;
                case '4':
                    ksiazkaAdresowa.wypiszWszystkichAdresatow();
                    break;
                case '5':
                    
                    break;
                case '6':
                  
                    break;
                case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    ksiazkaAdresowa.wylogowanieUzytkownika();
                    break;
            }
        }
    }
}
