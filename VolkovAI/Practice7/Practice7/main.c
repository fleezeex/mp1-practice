#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dop3.h"


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

    City* Cities = malloc((numCities+numVillages) * sizeof * Cities);
    Country* Countries = malloc(numCountries * sizeof * Countries);
    Continent* Continents = malloc(numContinents * sizeof * Continents);

    read(infilename, Cities, Countries, Continents, numCities, numVillages, numCountries, numContinents);

    /* for (int i = 0; i < numCountries; i++) {
        for (int a = 0; a < Countries[i].numofregions; a++) {
            printf("%s ", Countries[i].regions[a]);
        }
        printf("\n");
    }
    */

    ///regions(Cities, numCities, numVillages);

    ///while ((c = getchar()) != '\n' && c != EOF);

    ///countries_func(Cities, Countries, numCities, numVillages, numCountries);

    ///while ((c = getchar()) != '\n' && c != EOF);

    menu(Cities, Countries, Continents, numCities, numVillages, numCountries, numContinents);

    free(Cities);
    free(Countries);
    free(Continents);
    return 0;
}
