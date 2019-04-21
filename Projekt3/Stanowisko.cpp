#include <iostream>
#include <string>
#include "Headlines.h"
#include <fstream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Stanowisko::Stanowisko(int type){
    CzasAktualnyProces = 0;
    Podloze p1(-1);
    oczekujace.push_back(p1);
    Zakonczone.push_back(p1);
    available = true;
    if(type == 1){
        nazwa = "Czyszczenie podloza";
        CzasTrwania = 5;
    }
    else if(type == 2){
        nazwa = "Litografia";
        CzasTrwania = 10;
    }
    else if(type == 3){
        nazwa = "Trawienie";
        CzasTrwania = 15;
    }
    else if(type == 4){
        nazwa = "Implantacja";
        CzasTrwania = 10;
    }
    else if(type == 5){
        nazwa = "Wygrzewanie";
        CzasTrwania = 10;
    }
    else if(type == 6){
        nazwa = "Pomiary";
        CzasTrwania = 20;
    }
    else if(type == 7){
        nazwa = "Podzial na struktury";
        CzasTrwania = 15;
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Stanowisko::dodaj_do_kolejki( vector <Podloze> &SpisPodlozy ){
    for(unsigned int i = 0; i < SpisPodlozy.size(); i++){
        if( SpisPodlozy[i].DoPrzejscia.size() > 1 && SpisPodlozy[i].CzyUzywane == false && SpisPodlozy[i].DoPrzejscia[1] == nazwa && SpisPodlozy[i].ID != -1){
           SpisPodlozy[i].CzyUzywane = true;
           SpisPodlozy[i].Wprodukcji = true;
           oczekujace.push_back( SpisPodlozy[i] );
           available = false;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Stanowisko::pobierz_z_kolejki(){
    if( oczekujace.size() != 1 && available  == true){
        available = false;
    }
    else return;
}

void Stanowisko::koniec_procesu(vector <Podloze> &SpisPodlozy){
    if( CzasAktualnyProces == CzasTrwania && available == false && oczekujace.size() != 1){

        int index = oczekujace[1].ID+1;
        SpisPodlozy[index].CzyUzywane = false;
        oczekujace[1].CzyUzywane = false;
        SpisPodlozy[index].Zakonczone.push_back( SpisPodlozy[index].DoPrzejscia[1] );
        SpisPodlozy[index].DoPrzejscia.erase( SpisPodlozy[index].DoPrzejscia.begin()+1 );
        Zakonczone.push_back( oczekujace[1] );
        CzasAktualnyProces = 0;
        oczekujace.erase( oczekujace.begin()+1 );
        available = true;
    }
    else return;
}
void Stanowisko::przechwytywanie_czasu(){
    if( available == false)
        CzasAktualnyProces = CzasAktualnyProces + 5;
    else
        CzasAktualnyProces = 0;
    return;
}
void Stanowisko::save(fstream plik){
        /*plik << nazwa << endl;
        for(vector<Podloze>::iterator i = oczekujace.begin(); i < oczekujace.end(); i++){
            plik << oczekujace[i].ID << endl;

        }*/


    }
