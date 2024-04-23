#ifndef CONTINENT
#define CONTINENT
#include "Country.h"

typedef struct
{
    char name[buffer_size];
    int ncountries;
    Country* countries;
} Continent;

void continents_func(Country* Countries, Continent* Continents, int numContinents);
void allocateMemory(City** Cities, Region** Regions, Country** Countries, Continent** Continents, int numCities, int numRegions, int numCountries, int numContinents);
void deallocateMemory(City* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numRegions, int numCountries, int numContinents);
#endif