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

struct studentas {
    string var, pav;
    vector<int> paz;
    int egz;
    };

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void IvestiStudenta(vector<studentas>& grupe);
void GeneruotiPazymi(vector<studentas>& grupe);
void Spausdinti(vector<studentas>& grupe, int pasirinkimas);
void Nuskaitymas(vector<studentas>& grupe);

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
        cout<<"5. Baigti\n";
        cout<<"Pasirinkimas (Iveskite skaiciu):";
        cin>>pasirinkimas;

        if (cin.fail()){
            cout<<"Klaida! Iveskite skaiciu nuo 1 iki 5.\n";
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
            cout<<"Baigta.\n";
            break;
        }
        else{
            cout<<"Tokio pasirinkimo nera.\n";
        }
    }
}

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
    grupe.push_back(A);
}

void Spausdinti(vector<studentas>& grupe, int pasirinkimas){
    sort(grupe.begin(), grupe.end(), [](studentas a, studentas b){
        return a.pav < b.pav;
    });
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
        if (RodytiVid == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<GalutinisVid(B.paz, B.egz);
        if (RodytiMed == true) cout <<"|"<<right<<setw(17)<<fixed<<setprecision(2)<<GalutinisMed(B.paz, B.egz);
        cout <<"|\n";
    }
}
void Nuskaitymas(vector<studentas>& grupe){
    string failoPav;
    cout << "Iveskite failo pavadinima: ";
    cin >> failoPav;
    ifstream f(failoPav);

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
        grupe.push_back(A);
    }
    cout << "Nuskaityta studentu: " << grupe.size() << "\n";
    f.close();
}
