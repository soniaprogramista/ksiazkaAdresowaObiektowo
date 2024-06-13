#include <iostream>
using namespace std;

#include "KsiazkaAdresowa.hpp"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("read -n 1 -s -p\" Press any key to continue...\"");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
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

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(string login)
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
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    for (int i =0; i < uzytkownicy.size(); i ++)
    {
        cout << uzytkownicy[i].pobierzId()<<endl;
        cout << uzytkownicy[i].pobierzLogin()<<endl;
        cout << uzytkownicy[i].pobierzHaslo()<<endl;
    }
}
