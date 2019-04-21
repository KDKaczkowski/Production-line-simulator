#include <iostream>
#include <vector>
#include <string>
#include "Headlines.h"
#include <fstream>
using namespace std;

int main()
{
    int TIME = 0;
    int sterowanie, identyfikator;
    identyfikator = 0;
    vector <Stanowisko> SpisStanowisk;
    vector <Podloze> SpisPodlozy;
    SpisPodlozy.push_back(dodaj_do_spisu_podlozy(-1));
    //ofstream ofs("plik.txt", ios::out);
    for(int i = 1; i<8; i++){
        Stanowisko temp(i);
        SpisStanowisk.push_back(temp);
    }
    cout << "Witaj w symulatorze linii produkcyjnej ukladow scalonych." << endl;
    while(1){
        cout << endl << "----------MENU----------" << endl
        << "1. Utworz nowe podloze" << endl
        << "2. Dodaj krok produkcyjny dla podloza" << endl
        << "3. Zapisz do pliku historie podlozy" << endl
        << "4. Zapisz do pliku historie urzadzen" << endl
        << "5. Wyswietl podloza i ich kroki produkcyjne" << endl
        << "6. Wyswietl wybrane podloze i kroki jego produkcji" << endl
        << "7. Przewin czas o 5 jednostek" << endl
        << "8. Wyswietl historie wszystkich stanowisk" << endl
        << "9. Wyswietl historie danego stanowiska" << endl
        << "0. Zakoncz dzialanie programu" << endl
        << "Twoj wybor: ";
        cin >> sterowanie;
        if(sterowanie != 0 && sterowanie != 1 && sterowanie != 2 && sterowanie != 3 &&
            sterowanie != 4 && sterowanie != 5 && sterowanie != 6 && sterowanie != 7 && sterowanie != 8 && sterowanie != 9 ){  //Sprawdzenie czy wybrano mozliwa opcje z menu
            cout << "Nie ma takiej opcji w menu. Sprobuj jeszcze raz"<<endl;
            continue;
        }
        while(cin.fail()){
            cin.clear();
            cin.ignore(256,'\n');
            cout << endl << "Podaj raz jeszcze: ";
            cin >> sterowanie;
        }

        switch( sterowanie ){
        case 0:
            for(unsigned int i =0; i < SpisStanowisk.size(); i++)
                SpisStanowisk.pop_back();
            //ofs.close();
            return 0;
            break;
        case 1:

            SpisPodlozy.push_back(dodaj_do_spisu_podlozy(identyfikator));
            identyfikator++;
            continue;
        case 2:
            int wybor;
            Wyswietl_podloza_ID( SpisPodlozy );
            cout << "Podaj ID podloza dla ktorego chcesz dodac krok produkcyjny( podloza ktore trafily juz na linie, nie moga zmienic planu produkcji)"<< endl
            << "Twoj wybor: ";
            cin >> wybor;
            while( cin.fail() || wybor < 0 || wybor > identyfikator-1){
                cin.clear();
                cin.ignore(256,'\n');
                cout << endl << "Podaj raz jeszcze: ";
                cin >> wybor;
            }
            for(int i = 0; i < SpisPodlozy.size(); i++){
                if( SpisPodlozy[i].ID == wybor ){
                    if(SpisPodlozy[i].Wprodukcji == true){
                        cout << endl << "To podloze jest juz na linii produkcyjnej nie mozna zmienic planu" << endl;
                        break;
                    }
                    SpisPodlozy[i].dodaj_do_przebiegu( SpisStanowisk );
                    break;
                }
            }
            continue;
        case 3:
            continue;
        case 4:
            /*for(int i = 0; i < 7; i++)
                ofs << SpisPodlozy[i];*/
            continue;
        case 5:
            for(unsigned int i = 1; i < SpisPodlozy.size(); i++){
                cout<<SpisPodlozy[i]<< endl;
            }
            continue;
        case 6:
            int wybor3;
            Wyswietl_podloza_ID( SpisPodlozy );
            cout << "Podaj ID podloza ktore chcesz wyswietlic"<< endl
            << "Twoj wybor: ";
            cin >> wybor3;
            while( cin.fail() || wybor3 < 0 || wybor3 > identyfikator-1){
                cin.clear();
                cin.ignore(256,'\n');
                cout << endl << "Podaj raz jeszcze: ";
                cin >> wybor3;
            }
            cout << SpisPodlozy[wybor3+1] << endl;
            continue;
        case 7:
            TIME = TIME + 5;

            for(int i = 0; i<7; i++){
                SpisStanowisk[i].przechwytywanie_czasu();
                SpisStanowisk[i].dodaj_do_kolejki( SpisPodlozy );
                SpisStanowisk[i].pobierz_z_kolejki();
                SpisStanowisk[i].koniec_procesu( SpisPodlozy );
            }

            continue;
        case 8:
            for(int i = 0; i < 7; i++){
                cout << SpisStanowisk[i] << endl;
            }
            continue;
        case 9:
            for(int i = 0; i < 7; i++){
                cout << endl << i+1 << ". " << SpisStanowisk[i].nazwa;
            }
            cout << endl << "Podaj stanowisko ktore chcesz wyswietlic"<< endl
            << "Twoj wybor: ";
            cin >> wybor3;
            while( cin.fail() || wybor3 < 1 || wybor3 > 7){
                cin.clear();
                cin.ignore(256,'\n');
                cout << endl << "Podaj raz jeszcze: ";
                cin >> wybor3;
            }
            cout << SpisStanowisk[wybor3-1] << endl;
            continue;
        }

    }
    return 0;
}
