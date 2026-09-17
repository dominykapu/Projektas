#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::vector;

struct studentas {
    std::string var, pav;
    std::vector<int> paz;
    int egz;
    };

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void IvestiStudenta(vector<studentas>& grupe);
void GeneruotiPazymi(vector<studentas>& grupe);
void Spausdinti(vector<studentas>& grupe, int pasirinkimas);

int main(){
    srand(time(0));
    vector<studentas> grupe;

    while (true) {
        IvestiStudenta(grupe);
        char kl;
        cout << "Ar turite dar studentu? t/n ";
        cin >> kl;
        if (kl == 'n' || kl == 'N')
            break;
    }
    int pasirinkimas;
    cout<<"\nKaip skaiciuoti galutini bala?\n";
    cout << "\nKaip skaiciuoti galutini bala?\n";
    cout << "1. Pagal vidurki\n";
    cout << "2. Pagal mediana\n";
    cout << "3. Abu\n";
    cout << "Pasirinkimas (Iveskite 1, 2 arba 3): ";
    cin >> pasirinkimas;

    Spausdinti(grupe, pasirinkimas);
}

double GalutinisVid(vector<int> paz, int egz){
    double vid = std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
    return 0.4 * vid + 0.6 * egz;
}

double GalutinisMed(vector<int> paz, int egz){
    std::sort(paz.begin(), paz.end());
    int paz_sk = paz.size();
    double med;
    if (paz_sk%2 == 0) med = (paz[paz_sk/2-1]+paz[paz_sk/2])/2.0;
    else med = paz[paz_sk/2];
    return 0.4 * med + 0.6 * egz;

}

void IvestiStudenta(vector<studentas>& grupe){
    studentas A;
    cout<<"Iveskite varda: "; cin>>A.var;
    cout<<"Iveskite pavarde: "; cin>>A.pav;

    while (true){
        int n;
        char kl;
        cout<<"Iveskite semestro pazymi: "; cin>>n; A.paz.push_back(n);
        cout<<"Ar studentas turi dar pazymiu? t/n "; cin>>kl;
        if (kl == 'n' || kl == 'N') break;
    }

    cout<<"Iveskite egzamina: "; cin>>A.egz;

    grupe.push_back(A);
}

void GeneruotiPazymi(vector<studentas>& grupe){
    studentas A;
    cout<<"Iveskite varda: "; cin>>A.var;
    cout<<"Iveskite pavarde: "; cin>>A.pav;
    int kiek;
    cout<<"Kiek generuoti pazymiu? "; cin>>kiek;
    for (int i=0; i<kiek; i++){
        int pazymys=rand()%10+1;
        A.paz.push_back(pazymys);
    }
    A.egz=rand()%10+1;
    grupe.push_back(A);
}

void Spausdinti(vector<studentas>& grupe, int pasirinkimas){
    bool RodytiVid = (pasirinkimas == 1 || pasirinkimas == 3);
    bool RodytiMed = (pasirinkimas == 2 || pasirinkimas == 3);

    cout<<"\nStudento duomenys: \n";
    cout<<"|"<<left<<setw(15)<<"Vardas"<<"|"<<left<<setw(20)<<"Pavarde";
    if (RodytiVid==true) cout<<"|"<<right<<setw(15)<<"Galutinis (Vid)";
    if (RodytiMed==true) cout<<"|"<<right<<setw(15)<<"Galutinis (Med)";
    cout<<"|\n";


    int br=15+20+1; // Bruksniai
    if (RodytiVid==true) br+=15+1;
    if (RodytiMed==true) br+=15+1;

    cout<<"|";for (int i=0; i<br; i++) cout<<"-"; cout<<"|\n";

    for (auto B : grupe)
    {
        cout<<"|"<<left<<setw(15)<<B.var<<"|"<<left<<setw(20)<<B.pav;
        if (RodytiVid==true) cout<<"|"<<right<<setw(15)<<std::fixed<<std::setprecision(2)<<GalutinisVid(B.paz, B.egz);
        if (RodytiMed==true) cout<<"|"<<right<<setw(15)<<std::fixed<<std::setprecision(2)<<GalutinisMed(B.paz, B.egz);
        cout<<"|\n";
    }
}
