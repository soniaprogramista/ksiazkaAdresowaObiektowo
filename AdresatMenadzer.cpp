#include "AdresatMenadzer.hpp"
#include "MetodyPomocnicze.hpp"


void AdresatMenadzer::dodajAdresata()
{
    Adresat adresat;
    system("clear");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    cout << endl;
    cout << "Adresat zostal dodany"<< endl;
    system("read -n 1 -s -p\" Press any key to continue...\"");
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    string imie, nazwisko;
    adresat.ustawId(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

vector <Adresat> AdresatMenadzer:: wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
   adresaci =  plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    return adresaci;
}

void AdresatMenadzer::wypiszWszystkichAdresatow()
{
    for (int i =0; i < adresaci.size(); i ++)
    {
        cout << adresaci[i].pobierzId()<<endl;
        cout << adresaci[i].pobierzImie()<<endl;
        cout << adresaci[i].pobierzNazwisko()<<endl;
        cout << adresaci[i].pobierzNumerTelefonu()<<endl;
        cout << adresaci[i].pobierzEmail()<<endl;
        cout << adresaci[i].pobierzAdres()<<endl;
        cout << endl;
    }
    system("read -n 1 -s -p\" Press any key to continue...\"");

}

/*int AdresatMenadzer::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}
*/
