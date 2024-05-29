#ifndef LIBRARY
#define LIBRARY
#include "Continent.h"

typedef struct
{
    int ncontinents;
    Continent* continents;
} Library;

void read(const char* infilename, Library* Lib);
void menu(Library* Lib);
void deallocateMemory(Library* Lib);
void cities_func(Library* Lib);
void regions_func(Library* Lib);
void countries_func(Library* Lib);
void continents_func(Library* Lib);
#endif