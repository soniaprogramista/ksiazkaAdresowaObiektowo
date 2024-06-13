#include <iostream>
using namespace std;
#include <vector>

#include "Uzytkownik.hpp"


class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;
    
    vector <Uzytkownik> uzytkownicy;
    
public:
    void rejestracjaUzytkownika();
    
    
};
