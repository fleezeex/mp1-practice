#pragma once
#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <stdio.h>

#define buffer_size 170

typedef struct
{
    char name[buffer_size];
    char coor1[buffer_size];
    char coor2[buffer_size];
    int population;
} City;

typedef struct
{
    char name[buffer_size];

    int ncities;
    City* cities;

    int population;
} Region;

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


typedef struct
{
    char name[buffer_size];

    int ncountries;
    Country* countries;
    
} Continent;

/// void cities_func(City* Cities, int numCities, int numVillages);

#endif