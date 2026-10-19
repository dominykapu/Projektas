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
#include <list>
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
using std::list;

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

void Rikiuoti(vector<studentas>& grupe, int rikiuoti){
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
}

void Rikiuoti(list<studentas>& grupe, int rikiuoti){
    if (rikiuoti == 1){
        grupe.sort([](studentas a, studentas b){
        return a.pav < b.pav;
    });
    }
    if (rikiuoti == 2){
        grupe.sort([](studentas a, studentas b){
        return a.var < b.var;
    });
    }
    if (rikiuoti == 3){
        grupe.sort([](studentas a, studentas b){
        return a.galutinis < b.galutinis;
    });
    }
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

