#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

struct studentas {
    std::string var, pav;
    std::vector<int> paz;
    int egz, rez;
    };

int main(){
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
    cout<<"Studento duomenys: \n";
    cout<<left<<setw(15)<<A.var<<left<<setw(20)<<A.pav;
    for (int sk: A.paz) cout<<right<<setw(5)<<sk;
    cout<<right<<setw(10)<<A.egz;

}
