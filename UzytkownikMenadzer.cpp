#include "UzytkownikMenadzer.hpp"
#include "MetodyPomocnicze.hpp"
#include "PlikZUzytkownikami.hpp"

void UzytkownikMenadzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("read -n 1 -s -p\" Press any key to continue...\"");
}

Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    string haslo;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenadzer::czyIstniejeLogin(string login)
{
    for (int i =0; i < uzytkownicy.size(); i++)
    {
        if(login == uzytkownicy[i].pobierzLogin())
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else i++;
        
    }return false;
    
}
void UzytkownikMenadzer::wypiszWszystkichUzytkownikow()
{
    for (int i =0; i < uzytkownicy.size(); i ++)
    {
        cout << uzytkownicy[i].pobierzId()<<endl;
        cout << uzytkownicy[i].pobierzLogin()<<endl;
        cout << uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikMenadzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenadzer::logowanieUzytkownika()
{
        Uzytkownik uzytkownik;
        string login = "", haslo = "";

        cout << endl << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();

        vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
        while (itr != uzytkownicy.end())
        {
            if (itr -> pobierzLogin() == login)
            {
                for (int iloscProb = 3; iloscProb > 0; iloscProb--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                    haslo = MetodyPomocnicze::wczytajLinie();

                    if (itr -> pobierzHaslo() == haslo)
                    {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        this_thread::sleep_for(2000ms);                    
                        return itr -> pobierzId();
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                this_thread::sleep_for(2000ms);
                return 0;
            }
            itr++;
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        this_thread::sleep_for(2000ms);
        return 0;
}

void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            this_thread::sleep_for(2000ms);
        }
    }
    
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenadzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    return idZalogowanegoUzytkownika;
}
