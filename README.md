# Studentų galutinio balo skaičiavimo programa

Programa skaičiuoja studentų galutinį balą (0.4 * namų darbų vidurkis arba mediana + 0.6 * egzaminas).
Duomenis galima įvesti ranka, sugeneruoti atsitiktinai arba nuskaityti iš failo.

## v.pradinė:

- įvedimas ranka;
- vidurkis ir mediana;
- generavimas;
- meniu.

## v0.1:

- pridėtas nuskaitymas iš failo;
- įvesties tikrinimas.

## v0.2:

- kodas išskaidytas į .h ir .cpp failus;
- pridėtas atsitiktinių studentų failų generavimas;
- studentai skirstomi į dvi grupes: vargsiukai (galutinis balas < 5.0), galvociai (galutinis balas >= 5.0);
- Abi grupės rūšiuojamos pagal vartotojo pasirinktą parametrą (pavardė, vardas arba galutinis balas) ir išvedamos į du naujus failus;
- Pridėtas kiekvieno žingsnio laiko matavimas (failo kūrimas, nuskaitymas, skirstymas, rūšiavimas, išvedimas).

### Testavimo rezultatai (3 testų vidurkis, sekundėmis)

#### Failų generavimas ir duomenų nuskaitymas

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Failų generavimas | 0,002 | 0,010 | 0,048 | 0,461 | 4,270 |
| Duomenų nuskaitymas | 0,003 | 0,024 | 0,128 | 1,225 | 12,102 |

#### Studentų rūšiavimas į dvi grupes/kategorijas

| Rūšiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,0008 | 0,0068 | 0,0495 | 0,4265 | 4,0450 |
| Pagal vardą | 0,0008 | 0,0069 | 0,0509 | 0,4382 | 4,3159 |
| Pagal galutinį balą | 0,0008 | 0,0065 | 0,0486 | 0,4357 | 4,3792 |

#### Surūšiuotų studentų išvedimas į du naujus failus

| Rūšiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,003 | 0,015 | 0,144 | 1,389 | 13,906 |
| Pagal vardą | 0,003 | 0,016 | 0,116 | 1,697 | 14,142 |
| Pagal galutinį balą | 0,003 | 0,016 | 0,152 | 1,611 | 15,893 |

### Išvados

- Visų žingsnių laikas auga maždaug tiesiškai: padidinus įrašų skaičių 10 kartų, laikas taip pat padidėja apie 10 kartų.
- Rūšiavimo parametras (pavardė, vardas ar galutinis balas) laikui įtakos turi nedaug: skirtumai nežymūs, ypač mažesniems failams.

## v0.3:

- programa veikia su dviem konteineriais: `std::vector` ir `std::list` (pasirenkama paleidus programą);
- funkcijos perrašytos kaip šablonai, kad tiktų abiem konteineriams;
- rankinio įvedimo metu išvedamas studento objekto adresas atmintyje;

### Testavimo sistema

- CPU: Intel Core Ultra 7 155H, branduoliai: 16
- RAM: 32 GB, 7467 MT/s
- Diskas: SSD (NVMe), C:
- OS: Windows 11 64-bit

### Testavimo rezultatai (3 testų vidurkis, sekundėmis)

Testai atlikti su tais pačiais iš anksto sugeneruotais failais abiem konteineriams.

### std::vector

#### Duomenų nuskaitymas

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Nuskaitymas | 0,003 |  0,035 |  0,232 | 1,967 | 18,517 |

#### Studentų skirstymas į dvi grupes

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Skirstymas | 0,0008 | 0,005 | 0,049 | 0,422 | 4,316 |

#### Rikiavimas

| Rikiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,006 | 0,078 |  0,965 | 13,643 | 159,889 |
| Pagal vardą | 0,006 | 0,079 | 1,01 | 13,693 | 142,82 |
| Pagal galutinį balą | 0,004 | 0,046 | 0,534 | 7,336 | 100,335 |
 
#### Išvedimas į du naujus failus

| Rikiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,003 | 0,017 | 0,124 | 1,513 | 14,345 |
| Pagal vardą | 0,003 | 0,015 | 0,135 | 1,410 | 14,8561 |
| Pagal galutinį balą | 0,003 | 0,016 | 0,156 | 1,576 | 17,408 |

### std::list

#### Duomenų nuskaitymas

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Nuskaitymas | 0,003 | 0,025 | 0,214 | 1,933 | 19,761 |

#### Studentų skirstymas į dvi grupes

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Skirstymas | 0,0008 | 0,006 | 0,052 | 0,456 | 4,762 |

#### Rikiavimas

| Rikiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,002 | 0,026 | 0,279 | 3,911 | 38,341 |
| Pagal vardą | 0,002 | 0,027 | 0,281 | 3,778 | 38,672 |
| Pagal galutinį balą | 0,003 | 0,035 | 0,453 | 6,240 | 81,825 |

#### Išvedimas į du naujus failus

| Rikiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,004 | 0,018 | 0,149 | 1,622 | 15,607 |
| Pagal vardą | 0,003 | 0,019 | 0,148 | 1,653 | 16,091 |
| Pagal galutinį balą | 0,003 | 0,017 | 0,238 | 1,836 | 18,711 |

### Atminties adresai
**std::vector**

<img width="306" height="149" alt="Screenshot vector" src="https://github.com/user-attachments/assets/54cfc708-652b-4be1-8200-4aa05548ba13" />

3-io ir 4-o studento adresai artimi, vadinasi, vector elementai guli gretimai.

**std::list**

<img width="306" height="149" alt="Screenshot list" src="https://github.com/user-attachments/assets/cf474e47-6234-4864-9360-ba03870b5911" />

List adresų skirtumai nepastovūs.

### Išvados

- **Nuskaitymas:** vector ir list laikai beveik vienodi (10 000 000 įrašų: 18,5 s ir 19,8 s).
- **Skirstymas:** abiejų konteinerių laikai panašūs (10 000 000 įrašų: 4,3 s ir 4,8 s).
- **Rikiavimas:** pagal pavardę ir vardą list daug greitesnis (10 000 000 įrašų: list apie 38 s, o vector 143-160 s). Pagal galutinį balą skirtumas mažesnis (list 82 s, vector 100 s).
- **Išvedimas į failus:** vector ir list laikai panašūs, nes tai nepriklauso nuo konteinerio.
- Atminties adresai parodo, kad vector elementai gretimi, o list išsibarstę.

