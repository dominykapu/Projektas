#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include <vector>
#include "studentas.h"
using std::vector;

double GalutinisVid(vector<int> paz, int egz);
double GalutinisMed(vector<int> paz, int egz);
void IvestiStudenta(vector<studentas>& grupe);
void GeneruotiPazymi(vector<studentas>& grupe);
void Spausdinti(vector<studentas>& grupe, int pasirinkimas, int rikiuoti);
void Nuskaitymas(vector<studentas>& grupe);
void GeneruotiFaila(int kiek);
void SkirstytiStudentus(vector<studentas>& grupe);

#endif // FUNKCIJOS_H_INCLUDED
