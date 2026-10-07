#include "funkcijos.h"

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
#include <chrono>
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
using std::ofstream;
using std::getline;
using std::stringstream;

double GalutinisVid(vector<int> paz, int egz){
    if (paz.empty()){ //Kad nebutu dalybos is nulio
        return 0;
    }
    double vid = accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * vid + 0.6 * egz;
}

double GalutinisMed(vector<int> paz, int egz){
    if (paz.empty()){ //Kad nebutu dalybos is nulio
        return 0;
    }
    sort(paz.begin(), paz.end());
    int paz_sk = paz.size();
    double med;
    if (paz_sk%2 == 0) med = (paz[paz_sk/2-1]+paz[paz_sk/2])/2.0;
    else med = paz[paz_sk/2];
    return 0.4 * med + 0.6 * egz;
}

void IvestiStudenta(vector<studentas>& grupe){
    studentas A;
    cout << "Iveskite varda: ";
    cin >> A.var;
    cout << "Iveskite pavarde: ";
    cin >> A.pav;

    while (true){
        int n;
        char kl;
        while (true){
            cout << "Iveskite semestro pazymi: ";
            cin >> n;

            if (cin.fail()){
                cout << "Klaida! Iveskite skaiciu.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (n < 1 || n > 10){
                cout << "Klaida! Pazymys turi buti nuo 1 iki 10.\n";
            }
            else{
                A.paz.push_back(n);
                break;
            }
        }
        cout << "Ar studentas turi dar pazymiu? t/n ";
        cin >> kl;
        if (kl == 'n' || kl == 'N'){
            break;
        }
    }
    while (true){
        cout <<"Iveskite egzamina: ";
        cin >>A.egz;

        if (cin.fail()){
            cout <<"Klaida! Iveskite skaiciu.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (A.egz<1 || A.egz>10){
            cout <<"Klaida! Pazymys turi buti nuo 1 iki 10.\n";
        }
        else{
            break;
        }
    }

    A.galutinis = GalutinisVid(A.paz, A.egz);
    grupe.push_back(A);
}

void GeneruotiPazymi(vector<studentas>& grupe){
    studentas A;
    cout <<"Iveskite varda: "; cin>>A.var;
    cout <<"Iveskite pavarde: "; cin>>A.pav;
    int kiek;
    while (true){
        cout <<"Kiek generuoti pazymiu?: ";
        cin >> kiek;

        if (cin.fail()){
            cout <<"Klaida! Iveskite skaiciu.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (kiek<1){
            cout <<"Klaida! Pazymiu turi buti bent vienas.\n";
        }
        else{
            break;
        }
    }
    for (int i=0; i<kiek; i++){
        int pazymys=rand()%10+1;
        A.paz.push_back(pazymys);
    }
    A.egz=rand()%10+1;
    A.galutinis = GalutinisVid(A.paz, A.egz);
    grupe.push_back(A);
}

void Spausdinti(vector<studentas>& grupe, int pasirinkimas, int rikiuoti){
    auto pradzia=std::chrono::high_resolution_clock::now();

    if (rikiuoti == 1){
        sort(grupe.begin(), grupe.end(), [](studentas a, studentas b){
        return a.pav < b.pav;
    });
    }
    if (rikiuoti == 2){
        sort(grupe.begin(), grupe.end(), [](studentas a, studentas b){
        return a.var < b.var;
    });
    }
    if (rikiuoti == 3){
        sort(grupe.begin(), grupe.end(), [](studentas a, studentas b){
        return a.galutinis < b.galutinis;
    });
    }
    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;
    cout<<"Rikiavimo laikas: "<<laikas.count()<<"\n";

    bool RodytiVid = (pasirinkimas == 1 || pasirinkimas == 3);
    bool RodytiMed = (pasirinkimas == 2 || pasirinkimas == 3);

    cout <<"\nStudento duomenys: \n";
    cout <<"|"<<left<<setw(15)<<"Vardas"<<"|"<<left<<setw(20)<<"Pavarde";
    if (RodytiVid == true) cout<<"|"<<right<<setw(17)<<"Galutinis (Vid.)";
    if (RodytiMed == true) cout<<"|"<<right<<setw(17)<<"Galutinis (Med.)";
    cout <<"|\n";

    int br=15+20+1; // Bruksniai
    if (RodytiVid == true) br+=17+1;
    if (RodytiMed == true) br+=17+1;

    cout <<"|";for (int i=0; i<br; i++) cout<<"-"; cout<<"|\n";

    for (auto B : grupe)
    {
        cout <<"|"<<left<<setw(15)<<B.var<<"|"<<left<<setw(20)<<B.pav;
        if (RodytiVid == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<B.galutinis;
        if (RodytiMed == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<GalutinisMed(B.paz, B.egz);
        cout <<"|\n";
    }
}
void Nuskaitymas(vector<studentas>& grupe){
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    ifstream f(failoPav);

    auto pradzia=std::chrono::high_resolution_clock::now();

    if (!f){
        cout << "Nepavyko atidaryti failo.\n";
        return;
    }
    string antraste;
    getline(f, antraste);

    string eilute;
    while (getline(f, eilute)){
        stringstream ss(eilute);
        studentas A;
        ss >> A.var;
        ss >> A.pav;

        int pazymys;
        while (ss >> pazymys){
            A.paz.push_back(pazymys);
        }
        if (!ss.eof() || A.paz.empty()){ //Jei yra raide ciklas sustoja, nes raide negali buti ideta i pazymys
            cout << "Klaida faile, eilute praleista: " << eilute << "\n";
            continue;
            }
        A.egz = A.paz.back();
        A.paz.pop_back();
        A.galutinis = GalutinisVid(A.paz, A.egz);
        grupe.push_back(A);
    }
    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;

    cout<<"Nuskaityta studentu: "<<grupe.size()<<"\n";
    cout<<"Nuskaitymo laikas: "<<laikas.count()<<"\n";
    f.close();
}
void GeneruotiFaila(int kiek){
    auto pradzia=std::chrono::high_resolution_clock::now();

    string failoPav = "studentai" + std::to_string(kiek) + ".txt";
    ofstream f(failoPav);

    int nd=5;
    f<<"Vardas Pavarde";
    for (int i=1; i<=nd; i++) f<<" ND"<<i;
    f<<" Egz.\n";
    for (int i=1; i<=kiek; i++){
        f<<"Vardas"<<i<<" Pavarde"<<i;
        for (int j=0; j<nd; j++) f<<" "<<rand()%10+1;
        f<<" "<<rand()%10+1 <<"\n";
    }
    f.close();

    auto pabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas=pabaiga-pradzia;

    cout<<"Failo kurimo laikas: "<<laikas.count()<<"\n";
}
void SkirstytiStudentus(vector<studentas>& grupe, int rikiuoti){
    auto pradzia=std::chrono::high_resolution_clock::now();

    vector<studentas> vargsiukai;
    vector<studentas> galvociai;

    for (auto A : grupe){
        if (A.galutinis<5.0) vargsiukai.push_back(A);
        else galvociai.push_back(A);
    }

    if (rikiuoti==1){
        sort(vargsiukai.begin(), vargsiukai.end(), [](studentas a, studentas b){
             return a.pav < b.pav;
        });
        sort(galvociai.begin(), galvociai.end(), [](studentas a, studentas b){
             return a.pav < b.pav;
        });
    }
    if (rikiuoti==2){
        sort(vargsiukai.begin(), vargsiukai.end(), [](studentas a, studentas b){
             return a.var < b.var;
        });
        sort(galvociai.begin(), galvociai.end(), [](studentas a, studentas b){
             return a.var < b.var;
        });
    }
    if (rikiuoti==3){
        sort(vargsiukai.begin(), vargsiukai.end(), [](studentas a, studentas b){
             return a.galutinis < b.galutinis;
        });
        sort(galvociai.begin(), galvociai.end(), [](studentas a, studentas b){
             return a.galutinis < b.galutinis;
        });
    }

    auto skirstymoPabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> skirstymoLaikas=skirstymoPabaiga-pradzia;

    auto isvedimoPradzia=std::chrono::high_resolution_clock::now();

    ofstream vargsiukaiFailas("vargsiukai.txt");
    ofstream galvociaiFailas("galvociai.txt");

    for (auto A : vargsiukai){
        vargsiukaiFailas<<A.var<<" "<<A.pav<<" "<<A.galutinis<<"\n";
    }
    for (auto A : galvociai){
        galvociaiFailas<<A.var<<" "<<A.pav<<" "<<A.galutinis<<"\n";
    }
    vargsiukaiFailas.close();
    galvociaiFailas.close();

    auto isvedimoPabaiga=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> isvedimoLaikas=isvedimoPabaiga-isvedimoPradzia;

    cout<<"Studentai suskirstyti.\n";
    cout<<"Skirstymo laikas: "<<skirstymoLaikas.count()<<" \n";
    cout<<"Isvedimo i failus laikas: "<<isvedimoLaikas.count()<<"\n";
}

