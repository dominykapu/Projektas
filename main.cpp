#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
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
    double rez;
    };

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void IvestiStudenta(vector<studentas>& grupe);
void Spausdinti(vector<studentas>& grupe);

int main(){
    studentas A;
    vector<studentas> grupe;

    while (true) {
        IvestiStudenta(grupe);
        char kl;
        cout << "Ar turite dar studentu? t/n ";
        cin >> kl;
        if (kl == 'n' || kl == 'N')
            break;
    }
    Spausdinti(grupe);
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
    A.rez = GalutinisVid(A.paz, A.egz);

    grupe.push_back(A);
}

void Spausdinti(vector<studentas>& grupe){
    cout<<"Studento duomenys: \n";
    cout<<"|"<<left<<setw(15)<<"Vardas"<<"|"<<left<<setw(20)<<"Pavarde";
    cout<<"|"<<right<<setw(15)<<"Galutinis (Vid)"<<"|\n";

    int br=15+20+15+2; // Bruksniai
    cout<<"|";for (int i=0; i<br; i++) cout<<"-"; cout<<"|\n";

    for (auto B : grupe)
    {
        cout<<"|"<<left<<setw(15)<<B.var<<"|"<<left<<setw(20)<<B.pav;
        cout<<"|"<<right<<setw(15)<<std::fixed<<std::setprecision(2)<<B.rez<<"|\n";
    }
}
