#ifndef DOP3_H
#define DOP3_H
#include <stdlib.h>
#include <stdio.h>
#include "dop2.h"

#define buffer_size 170

typedef struct
{
    char name[buffer_size];
    int numofcountries;
    char temp_countries[buffer_size * 10];
    char* countries[buffer_size];
} Continent;

void read(const char* infilename, City* Cities, Country* Countries, Continent *Continents, int numCities, int numVillages, int numCountries, int numContinents);
void continents_func(City* Cities, Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents);
void menu(City* Cities, Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents);
#endif