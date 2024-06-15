#include "AdresatMenadzer.hpp"
#include "MetodyPomocnicze.hpp"


int AdresatMenadzer::dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    system("clear");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return idOstatniegoAdresata+1;
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    string imie, nazwisko;
    adresat.ustawId(idOstatniegoAdresata+1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

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
        cout << adresaci[i].pobierzIdUzytkownika()<<endl;
        cout << adresaci[i].pobierzImie()<<endl;
        cout << adresaci[i].pobierzNazwisko()<<endl;
        cout << adresaci[i].pobierzNumerTelefonu()<<endl;
        cout << adresaci[i].pobierzEmail()<<endl;
        cout << adresaci[i].pobierzAdres()<<endl;
    }
}
/*int AdresatMenadzer::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}
*/
