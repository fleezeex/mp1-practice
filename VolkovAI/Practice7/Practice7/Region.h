#ifndef REGION
#define REGION
#include "City.h"

typedef struct
{
    char name[buffer_size];

    int ncities;
    int nvillages;
    City* cities;

    int population;
} Region;

void regions(Region* Regions, City* Cities, int numCities, int numVillages, int numRegions);
#endif
