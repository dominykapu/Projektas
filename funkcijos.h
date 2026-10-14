#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <vector>
#include <list>
#include <iostream>
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

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void Spausdinti(vector<studentas>& grupe, int pasirinkimas, int rikiuoti);
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
#endif // FUNKCIJOS_H_INCLUDED
