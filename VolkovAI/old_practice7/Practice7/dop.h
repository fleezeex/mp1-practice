#pragma once
#ifndef DOP_H
#define DOP_H
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
    int population;
} Region;

typedef enum
{

} GovermentForm;

typedef struct
{

    char name[buffer_size];

    Region* regions;
    int nregions;
    
    float square;
    int population;
    GovermentForm form;
    City capital;
} Country;


typedef struct
{
    char name[buffer_size];

    Country* countries;
    int ncountries;
} Continent;

void cities_func(City* Cities, int numCities, int numVillages);
void regions(City* Cities, int numCities, int numVillages);
int numof(const char* infilename, int numCities, int numVillages, int numCountries);
#endif
