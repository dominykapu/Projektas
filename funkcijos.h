#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "studentas.h"
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::string;
using std::ifstream;
using std::getline;
using std::stringstream;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void Rikiuoti(vector<studentas>& grupe, int rikiuoti);
void Rikiuoti(list<studentas>& grupe, int rikiuoti);
void GeneruotiFaila(int kiek);
void SkirstytiStudentus(vector<studentas>& grupe, int rikiuoti);


template <class T>
void IvestiStudenta(T& grupe){
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
template <class T>
void GeneruotiPazymi(T& grupe){
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
template <class T>
void Nuskaitymas(T& grupe){
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    ifstream f(failoPav);

    auto pradzia=std::chrono::high_resolution_clock::now();

    if (!f){
        cout << "Nepavyko atidaryti failo.\n";
        return;
    }
    grupe.clear();

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
template <class T>
void Spausdinti(T& grupe, int pasirinkimas, int rikiuoti){
    auto pradzia=std::chrono::high_resolution_clock::now();

    Rikiuoti(grupe, rikiuoti);

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
#endif // FUNKCIJOS_H_INCLUDED
