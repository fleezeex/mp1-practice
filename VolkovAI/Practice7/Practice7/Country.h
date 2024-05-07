#ifndef COUNTRY
#define COUNTRY
#include "Region.h"

typedef enum
{
    Monarchy = 0,
    Republic = 1
} GovermentForm;

typedef struct
{

    char name[buffer_size];
    float square;
    int population;
    GovermentForm form;       
    City capital;

    int nregions;
    Region* regions;
} Country;

#endif