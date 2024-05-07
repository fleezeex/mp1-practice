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



#endif
