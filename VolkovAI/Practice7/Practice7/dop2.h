#ifndef DOP2_H
#define DOP2_H
#include <stdlib.h>
#include <stdio.h>
#include "dop.h"

#define buffer_size 170

typedef struct
{
    char name[buffer_size];
    int numofregions;
    char region_temp[buffer_size * 10];
    char* regions[buffer_size];
    char form_of_government[buffer_size];
    char capital[buffer_size];
} Country;

void countries_func(City* Cities, Country* Countries, int numCities, int numVillages, int numCountries);

#endif
