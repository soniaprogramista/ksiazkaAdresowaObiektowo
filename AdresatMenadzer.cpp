#include "AdresatMenadzer.hpp"
#include "MetodyPomocnicze.hpp"
#include <thread>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

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
void AdresatMenadzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;
    Adresat adresat;
    
    system("clear");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();

        for (int i = 0; i < adresaci.size(); i ++)
        {
            if (adresaci[i].pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
        system("read -n 1 -s -p\" Press any key to continue...\"");
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
        this_thread::sleep_for(2000ms);
    }
    cout << endl;
}

void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
    
}

void AdresatMenadzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenadzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("clear");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();

        for (int i = 0; i < adresaci.size(); i++)
        {
            if (adresaci[i].pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(adresaci[i]);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
        system("read -n 1 -s -p\" Press any key to continue...\"");
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
        this_thread::sleep_for(2000ms);
    }
    cout << endl;
}

int AdresatMenadzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("clear");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i =0; i < adresaci.size(); i ++)
    {
        if (idUsuwanegoAdresata == adresaci[i].pobierzId())
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                PlikZAdresatami::usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("read -n 1 -s -p\" Press any key to continue...\"");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("read -n 1 -s -p\" Press any key to continue...\"");
    }
    return 0;
}

int AdresatMenadzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
/*int AdresatMenadzer::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}
*/
int AdresatMenadzer::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}
