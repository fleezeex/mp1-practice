#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dop.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    char* infilename = "test.txt";
    int numCities = 0, numVillages = 0;

    numCities = numof(infilename, numCities);
    numVillages = numof(infilename, numCities);

    City* Cities = malloc((numCities+numVillages) * sizeof * Cities);

    read(infilename, Cities, numCities, numVillages);

    oblasti(Cities, numCities, numVillages);

    free(Cities);
    return 0;
}
