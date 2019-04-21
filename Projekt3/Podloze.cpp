#include <iostream>
#include <vector>
#include <string>
#include "Headlines.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Podloze::Podloze(int identyfikator){
    DoPrzejscia.push_back( "Poczatek" );
    Zakonczone.push_back( "Poczatek" );
    DoPrzejscia.push_back( "Czyszczenie podloza" );
    DoPrzejscia.push_back( "Podzial na struktury" );
    ID = identyfikator;
    CzyUzywane = false;
    Wprodukcji = false;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Podloze::~Podloze(){
    int length = DoPrzejscia.size();
    int length2 = Zakonczone.size();
    for(int i = 0; i < length; i++){
        DoPrzejscia.pop_back();
    }
    for(int i = 0; i < length2; i++){
        Zakonczone.pop_back();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Podloze::dodaj_do_przebiegu(vector <Stanowisko> &SpisStanowisk){
    int wybor, wybor2;
    cout << "Podaj jakie stanowisko chcesz dodac do przebiegu" << endl
    << "1. Czyszczenie podloza" << endl
    << "2. Litografia" << endl
    << "3. Trawienie" << endl
    << "4. Implantacja" << endl
    << "5. Wygrzewanie" << endl
    << "6. Pomiary" << endl
    << "7. Podzial na struktury" << endl;
    cin >> wybor;
    while( cin.fail() && wybor != 1 && wybor != 2 && wybor != 3 && wybor != 4 && wybor != 5 && wybor != 6 && wybor != 7){
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl << "Podaj raz jeszcze: ";
        cin >> wybor;
    }
    cout << "Podaj na ktorym miejscu ma byc ustawione to stanowisko(Nie mozna zmienic stanowiska poczatkowego i koncowego)" << endl;
    for(unsigned int i=1; i < DoPrzejscia.size(); i++){
        cout << i << ". " << DoPrzejscia[i] <<"    ";
    }
    cout << endl << "Twoj wybor: ";
    cin >> wybor2;
    while( cin.fail() || wybor2 <= 1 || wybor2 >= DoPrzejscia.size() ){
        cin.clear();
        cin.ignore(256,'\n');
        cout << endl << "Podaj raz jeszcze miejsce: ";
        cin >> wybor2;
    }
    DoPrzejscia.insert( DoPrzejscia.begin() + wybor2, SpisStanowisk[wybor-1].nazwa );
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Podloze::Przenies_do_zakonczonych(){
    Zakonczone.push_back( DoPrzejscia[0] );
    DoPrzejscia.erase( DoPrzejscia.begin() );
}

