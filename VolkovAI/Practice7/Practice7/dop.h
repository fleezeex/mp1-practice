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



void read(const char* infilename, City* Cities, int numCities, int numVillages);
void oblasti(City* Cities, int numCities);

#endif
