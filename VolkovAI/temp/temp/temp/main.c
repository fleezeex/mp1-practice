#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Continent.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    char* infilename = "test1.txt";
    int numCities = 0, numVillages = 0, numRegions = 0, numCountries = 0, numContinents = 0;
    int c;

    numCities = numof(infilename, numCities, numVillages, numRegions, numCountries);
    numVillages = numof(infilename, numCities, numVillages, numRegions, numCountries);
    numRegions = numof(infilename, numCities, numVillages, numRegions, numCountries);
    numCountries = numof(infilename, numCities, numVillages, numRegions, numCountries);
    numContinents = numof(infilename, numCities, numVillages, numRegions, numCountries);

    City* Cities = malloc((numCities + numVillages) * sizeof * Cities);
    Region* Regions = malloc(numRegions * sizeof * Regions);
    for (int i = 0; i < numRegions; i++) {
        Regions[i].cities = (City*)malloc((numCities + numVillages) * sizeof(City));
    }
    Country* Countries = malloc(numCountries * sizeof * Countries);
    for (int i = 0; i < numCountries; i++) {
        Countries[i].regions = (Region*)malloc(numRegions * sizeof(Region));
    }
    Continent* Continents = malloc(numContinents * sizeof * Continents);
    for (int i = 0; i < numCountries; i++) {
        Continents[i].countries = (Country*)malloc(numCountries * sizeof(Country));
    }

    read(infilename, Cities, Regions, Countries, Continents, numCities, numVillages, numRegions, numCountries, numContinents);

    menu(Cities, Regions, Countries, Continents, numCities, numVillages, numRegions, numCountries, numContinents);

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
