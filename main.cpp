#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

#include "funkcijos.h"

using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::accumulate;
using std::sort;
using std::fixed;
using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::stringstream;

int main(){
    srand(time(0));
    vector<studentas> grupe;

    while (true){
        int pasirinkimas;
        cout<<"\n=========== MENIU ============\n";
        cout<<"1. Ivesti studenta rankiniu budu\n";
        cout<<"2. Generuoti pazymius\n";
        cout<<"3. Nuskaityti is failo\n";
        cout<<"4. Spausdinti rezultatus\n";
        cout<<"6. Suskirstyti studentus\n";
        cout<<"7. Baigti\n";
        cout<<"Pasirinkimas (Iveskite skaiciu):";
        cin>>pasirinkimas;

        if (cin.fail()){
            cout<<"Klaida! Iveskite skaiciu nuo 1 iki 7.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (pasirinkimas == 1){
            IvestiStudenta(grupe);
        }
        else if (pasirinkimas == 2){
            GeneruotiPazymi(grupe);
        }
        else if (pasirinkimas == 3){
            Nuskaitymas(grupe);
        }
        else if (pasirinkimas == 4){
            int kaip;
            cout <<"\nKaip skaiciuoti galutini bala?\n";
            cout <<"1. Pagal vidurki\n";
            cout <<"2. Pagal mediana\n";
            cout <<"3. Abu\n";
            cout <<"Pasirinkimas (Iveskite 1, 2 arba 3): ";
            cin >>kaip;
            if (cin.fail()){
                cout <<"Klaida! Iveskite skaiciu nuo 1 iki 3.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (kaip<1 || kaip>3){
                cout <<"Klaida! Iveskite 1, 2 arba 3.\n";
            }
            else{
                Spausdinti(grupe, kaip);
            }
        }
        else if (pasirinkimas == 5){
            int kiek;
            cout<<"Kiek irasu generuoti? ";
            cin>>kiek;
            GeneruotiFaila(kiek);
            cout<<"Failas sukurtas.\n";
        }
        else if (pasirinkimas == 6){
                SkirstytiStudentus(grupe);
        }
        else if (pasirinkimas == 7){
            cout<<"Baigta.\n";
            break;
        }
        else{
            cout<<"Tokio pasirinkimo nera.\n";
        }
    }
}
