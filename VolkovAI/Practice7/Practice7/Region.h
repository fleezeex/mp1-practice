#ifndef REGION
#define REGION
#include "City.h"

typedef struct
{
    char name[buffer_size];

    int ncities;
    City* cities;

    City capital;
    int population;
} Region;
void regions_func(City* Cities, Region* Regions, int numCities, int numRegions);
#endif
