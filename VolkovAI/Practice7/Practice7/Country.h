#ifndef COUNTRY
#define COUNTRY
#include "Region.h"

typedef enum
{
    Монархия = 0,
    Республика = 1
} GovermentForm;

typedef struct
{

    char name[buffer_size];

    int nregions;
    Region* regions;

    float square;
    int population;
    GovermentForm form;
    City capital;
} Country;

#endif