#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp
#include "Adresat.hpp"
#include <stdio.h>

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string nazwaTymczasowegoPlikuZAdresatami;
public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };
    static void usunWybranaLinieWPliku(int numerUsuwanejLinii);

    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzZPlikuIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
     static void usunPlik(string nazwaPlikuZRozszerzeniem);
   static void zmienNazwePliku(string staraNazwa, string nowaNazwa);

};


#endif
