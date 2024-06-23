#ifndef PlikZAdresatami_hpp
#define PlikZAdresatami_hpp
#include "Adresat.hpp"
#include <stdio.h>
#include "PlikTekstowy.hpp"

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string nazwaTymczasowegoPlikuZAdresatami;
public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
    };
    void usunWybranaLinieWPliku(int numerUsuwanejLinii, vector <Adresat> adresaci);
    static string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    static void usunPlik(string nazwaPlikuZRozszerzeniem);
    static void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void dopiszAdresataDoPliku(Adresat adresat);
    int pobierzZPlikuIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);


};


#endif
