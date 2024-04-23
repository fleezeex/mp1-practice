#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Continent.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    char* infilename = "Input.txt"; // argc, argv
    int numCities = 0, numRegions = 0, numCountries = 0, numContinents = 0;
    int c;

    numCities = numof(infilename, numCities, numRegions, numCountries);
    numRegions = numof(infilename, numCities, numRegions, numCountries);
    numCountries = numof(infilename, numCities, numRegions, numCountries);
    numContinents = numof(infilename, numCities, numRegions, numCountries);

    City* Cities;
    Region* Regions;
    Country* Countries;
    Continent* Continents;

    allocateMemory(&Cities, &Regions, &Countries, &Continents, numCities, numRegions, numCountries, numContinents);

    read(infilename, Cities, Regions, Countries, Continents, numCities, numRegions, numCountries, numContinents);

    menu(Cities, Regions, Countries, Continents, numCities, numRegions, numCountries, numContinents);

    deallocateMemory(Cities, Regions, Countries, Continents, numCities, numRegions, numCountries, numContinents);

    return 0;
}
