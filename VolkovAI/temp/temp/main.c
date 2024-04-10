#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    char* infilename = "test.txt";
    int numCities = 0, numVillages = 0, numCountries = 0, numContinents = 0;
    int c;

    numCities = numof(infilename, numCities, numVillages, numCountries);
    numVillages = numof(infilename, numCities, numVillages, numCountries);
    numCountries = numof(infilename, numCities, numVillages, numCountries);
    numContinents = numof(infilename, numCities, numVillages, numCountries);

    City* Cities = malloc((numCities + numVillages) * sizeof * Cities);
    Country* Countries = malloc(numCountries * sizeof * Countries);
    Continent* Continents = malloc(numContinents * sizeof * Continents);

    read(infilename, Cities, Countries, Continents, numCities, numVillages, numCountries, numContinents);

    menu(Cities, Countries, Continents, numCities, numVillages, numCountries, numContinents);

    free(Cities);
    free(Countries);
    free(Continents);
    return 0;
}
