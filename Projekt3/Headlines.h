#ifndef HEADLINES_H_INCLUDED
#define HEADLINES_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Podloze;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Stanowisko{
    public:
    int CzasTrwania;
    int CzasAktualnyProces;
    string nazwa;
    vector <Podloze> oczekujace;
    vector <Podloze> Zakonczone;
    bool available;
public:
    friend std::ostream & operator<<(std::ostream &wyjscie, const Stanowisko &s);
    friend Podloze;
    Stanowisko( int type );
    void dodaj_do_kolejki( vector <Podloze> &SpisPodlozy );
    void pobierz_z_kolejki();
    void koniec_procesu(vector <Podloze> &SpisPodlozy);
    void przechwytywanie_czasu();
    void save(fstream plik);
    //ZAPIS DO PLIKU

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Podloze{
    public:
    vector <string> DoPrzejscia;
    vector <string> Zakonczone;
    bool CzyUzywane;
    bool Wprodukcji;
    int ID;
public:
    Podloze(int identyfikator);
    ~Podloze();
    //ZAPIS DO PLIKU
    void Przenies_do_zakonczonych();
    void save(string name);
    int dodaj_do_przebiegu( vector <Stanowisko> &SpisStanowisk );

    friend void Wyswietl_podloza_ID( vector <Podloze> SpisPodlozy );
    friend Podloze dodaj_do_spisu_podlozy( int identyfikator );
    friend Stanowisko;
    friend std::ostream & operator<<(std::ostream &wyjscie, const Podloze &s);
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Wyswietl_podloza_ID( vector <Podloze> SpisPodlozy );
void Wyswietl_podloza( vector <Podloze> SpisPodlozy, int ID_podloza = 9999 );
Podloze dodaj_do_spisu_podlozy( int identyfikator );
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // HEADLINES_H_INCLUDED
