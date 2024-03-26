#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dop.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    char* infilename = "lol.txt";
    int numCities = 0, numVillages = 0;

    numCities = numof(infilename, numCities);
    City* Cities = malloc(numCities * sizeof *Cities);
    numVillages = numof(infilename, numCities);
    if (numVillages > 0) {
        City* Villages = malloc(numVillages * sizeof * Villages);
    }
    read(infilename, Cities, numCities, numVillages);

    oblasti(Cities, numCities);

    free(Cities);
    return 0;
}
