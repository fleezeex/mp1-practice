#include "Continent.h"

void Allocation(Country* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numRegions, int numCountries, int numContinents) {
    Cities = malloc(numCities * sizeof * Cities);

    Regions = malloc(numRegions * sizeof * Regions);
    for (int i = 0; i < numRegions; i++) {
        Regions[i].cities = (City*)malloc(numCities * sizeof(City));
    }

    Countries = malloc(numCountries * sizeof * Countries);
    for (int i = 0; i < numCountries; i++) {
        Countries[i].regions = (Region*)malloc(numRegions * sizeof(Region));
    }

    Continents = malloc(numContinents * sizeof * Continents);
    for (int i = 0; i < numCountries; i++) {
        Continents[i].countries = (Country*)malloc(numCountries * sizeof(Country));
    }
}