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

    City* Cities;
    Region* Regions;
    Country* Countries;
    Continent* Continents;

    numCities = numof(infilename, numCities, numRegions, numCountries);
    numRegions = numof(infilename, numCities, numRegions, numCountries);
    numCountries = numof(infilename, numCities, numRegions, numCountries);
    numContinents = numof(infilename, numCities, numRegions, numCountries);

    Allocation(&Cities, &Regions, &Countries, &Continents, numCities, numRegions, numCountries, numContinents);
    read(infilename, Cities, Regions, Countries, Continents, numCities, numRegions, numCountries, numContinents);

    menu(Cities, Regions, Countries, Continents, numCities, numRegions, numCountries, numContinents);

    for (int i = 0; i < numRegions; i++) {
        free(Regions[i].cities);
    }
    for (int i = 0; i < numCountries; i++) {
        free(Countries[i].regions);
    }
    for (int i = 0; i < numContinents; i++) {
        free(Continents[i].countries);
    }
    free(Cities);
    free(Regions);
    free(Countries);
    free(Continents);
    return 0;
}
