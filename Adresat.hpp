#ifndef Adresat_hpp
#define Adresat_hpp
#include <iostream>
using namespace std;
#include <stdio.h>

class Adresat
{
    int id, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;
    
public:
    Adresat (int id= 0, int idUzytkownika= 0, string imie= "", string nazwisko= "", string numerTelefonu= "", string email= "", string adres= "")
    {
        this -> id = id;
        this -> idUzytkownika = idUzytkownika;
        this -> imie = imie;
        this -> nazwisko = nazwisko;
        this -> numerTelefonu = numerTelefonu;
        this -> email = email;
        this -> adres = adres;
    }
    
    void ustawId (int noweId);
    void ustawIdUzytkownika (int noweIdUzytkownika);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);
    
    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif /* Adresat_hpp */
