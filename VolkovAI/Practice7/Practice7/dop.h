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
    float square;
    char region[buffer_size];
} City;


void regions(City* Cities, int numCities, int numVillages);
int numof(const char* infilename, int numCities, int numVillages, int numCountries);
#endif
