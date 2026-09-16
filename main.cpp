#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
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

int main(){
    studentas A;
    vector<studentas> grupe;
    while (true){
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
    A.rez=0.4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6*A.egz;

    grupe.push_back(A);
    A.paz.clear();
    char kl;
    cout<<"Ar turite dar studentu? t/n "; cin>>kl;
        if (kl == 'n' || kl == 'N') break;
    }

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
