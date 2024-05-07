#pragma once
#ifndef CITY
#define CITY
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define buffer_size 170

typedef struct
{
    char name[buffer_size];
    char coor1[buffer_size];
    char coor2[buffer_size];
    int population;
} City;

#endif
