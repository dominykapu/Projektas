# Studentų galutinio balo skaičiavimo programa

Programa skaičiuoja studentų galutinį balą (0.4 * namų darbų vidurkis arba mediana + 0.6 * egzaminas).
Duomenis galima įvesti ranka, sugeneruoti atsitiktinai arba nuskaityti iš failo.

## Versijos:

### v.pradinė:

- įvedimas ranka;
- vidurkis ir mediana;
- generavimas;
- meniu.

### v0.1:

- pridėtas nuskaitymas iš failo;
- įvesties tikrinimas.

### v0.2:

- kodas išskaidytas į .h ir .cpp failus;
- pridėtas atsitiktinių studentų failų generavimas;
- studentai skirstomi į dvi grupes: vargsiukai (galutinis balas < 5.0), galvociai (galutinis balas >= 5.0);
- Abi grupės rūšiuojamos pagal vartotojo pasirinktą parametrą (pavardė, vardas arba galutinis balas) ir išvedamos į du naujus failus;
- Pridėtas kiekvieno žingsnio laiko matavimas (failo kūrimas, nuskaitymas, skirstymas, rūšiavimas, išvedimas).

## Testavimo rezultatai (3 testų vidurkis)

### Failų generavimas ir duomenų nuskaitymas

| Žingsnis | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Failų generavimas | 0,002 | 0,010 | 0,048 | 0,461 | 4,270 |
| Duomenų nuskaitymas | 0,003 | 0,024 | 0,128 | 1,225 | 12,102 |

### Studentų rūšiavimas į dvi grupes/kategorijas

| Rūšiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,0008 | 0,0068 | 0,0495 | 0,4265 | 4,0450 |
| Pagal vardą | 0,0008 | 0,0069 | 0,0509 | 0,4382 | 4,3159 |
| Pagal galutinį balą | 0,0008 | 0,0065 | 0,0486 | 0,4357 | 4,3792 |

### Surūšiuotų studentų išvedimas į du naujus failus

| Rūšiavimas | 1 000 | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|---|---|---|---|---|---|
| Pagal pavardę | 0,003 | 0,015 | 0,144 | 1,389 | 13,906 |
| Pagal vardą | 0,003 | 0,016 | 0,116 | 1,697 | 14,142 |
| Pagal galutinį balą | 0,003 | 0,016 | 0,152 | 1,611 | 15,893 |

### Išvados

- Visų žingsnių laikas auga maždaug tiesiškai: padidinus įrašų skaičių 10 kartų, laikas taip pat padidėja apie 10 kartų.
- Rūšiavimo parametras (pavardė, vardas ar galutinis balas) laikui įtakos turi nedaug: skirtumai nežymūs, ypač mažesniems failams.

