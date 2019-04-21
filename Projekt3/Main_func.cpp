#include <iostream>
#include <string>
#include "Headlines.h"
#include <vector>

using namespace std;

void Wyswietl_podloza_ID(vector <Podloze> SpisPodlozy){
    cout << endl;
    for(unsigned int i = 1; i < SpisPodlozy.size(); i++){
        cout << "Podloze o ID: " << SpisPodlozy[i].ID << endl;
    }
}

Podloze dodaj_do_spisu_podlozy(int identyfikator){
    Podloze p1(identyfikator);
    return p1;
}

std::ostream & operator<<(std::ostream &wyjscie, const Podloze &s){
    cout << endl<< "ID Podloza: " << s.ID << "    Kroki produkcyjne: ";
    cout << endl << "PROCESY DO PRZEJSCIA:";
    for(unsigned int j = 1; j < s.DoPrzejscia.size(); j++){
        cout << endl << "      " << j << ". " << s.DoPrzejscia[j];
    }
    cout << endl << "PROCESY ZAKONCZONE:" << endl;
    for(unsigned int j = 1; j < s.Zakonczone.size(); j++){
        cout << endl << "      " << j << ". " << s.Zakonczone[j];
    }
    return wyjscie;
}

std::ostream & operator<<(std::ostream &wyjscie, const Stanowisko &s){
    cout << endl << "Stanowisko: " << s.nazwa << endl
    << "Czas produkcji: " << s.CzasTrwania << endl
    << "Podloze znajdujace sie na stanowisku:";
    if( s.oczekujace.size() > 1){
        cout << endl << "   ID: " << s.oczekujace[1].ID << " Zostalo jeszcze " << s.CzasTrwania - s.CzasAktualnyProces << " Jednostek czasu do konca";
    }
    cout << endl << "Podloza oczekujace: ";
    if( s.oczekujace.size() > 2 ){
        for(unsigned int i = 2; i < s.oczekujace.size(); i++){
            cout << endl << "   ID: " << s.oczekujace[i].ID;
        }
    }
    cout << endl << "Podloza, ktore byly juz na tym stanowisku:";
    if(s.Zakonczone.size() > 1){
        for(unsigned int i = 1; i < s.Zakonczone.size(); i++){
            cout << endl << "   ID: " << s.Zakonczone[i].ID;
        }
    }
    return wyjscie;
}


