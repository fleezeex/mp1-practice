#ifndef CONTINENT
#define CONTINENT
#include "Country.h"

typedef struct
{
    char name[buffer_size];

    int ncountries;
    Country* countries;

} Continent;

#endif