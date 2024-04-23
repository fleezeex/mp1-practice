#include "Continent.h"

void allocateMemory(City** Cities, Region** Regions, Country** Countries, Continent** Continents, int numCities, int numRegions, int numCountries, int numContinents) {
    *Cities = malloc(numCities * sizeof(City));
    *Regions = malloc(numRegions * sizeof(Region));
    for (int i = 0; i < numRegions; i++) {
        (*Regions)[i].cities = (City*)malloc(numCities * sizeof(City));
    }

    *Countries = malloc(numCountries * sizeof(Country));
    for (int i = 0; i < numCountries; i++) {
        (*Countries)[i].regions = (Region*)malloc(numRegions * sizeof(Region));
    }

    *Continents = malloc(numContinents * sizeof(Continent));
    for (int i = 0; i < numContinents; i++) {
        (*Continents)[i].countries = (Country*)malloc(numCountries * sizeof(Country));
    }
}

void deallocateMemory(City* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numRegions, int numCountries, int numContinents) {
    for (int i = 0; i < numRegions; i++) {
        free(Regions[i].cities);
    }
    free(Regions);

    for (int i = 0; i < numCountries; i++) {
        free(Countries[i].regions);
    }
    free(Countries);

    for (int i = 0; i < numContinents; i++) {
        free(Continents[i].countries);
    }
    free(Continents);

    free(Cities);
}