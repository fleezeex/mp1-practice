#ifndef REGION
#define REGION
#include "City.h"

class Region
{
    public:
    string name;

    int ncities;
    City* cities;
    
    City capital;
    int population;

    Region();
    Region(string name, int population, string capitalname, int ncities);
    Region(const Region& region);
    ~Region();


    friend std::ifstream& operator>>(std::ifstream& in, Region& region)
    {
        char* temp;
        char* buffer;
        in >> temp;
        
        buffer = strtok (temp, ";");
        region.name = buffer;
        buffer = strtok (NULL, ";");
        region.population = atoi(buffer);
        buffer = strtok (NULL, ";");
        region.capital.name = buffer;
        buffer = strtok (NULL, ";");
        region.ncities = atoi(buffer);
        return in;
    }
};

std::istream& operator>>(std::istream& in, Region& region);
//void regions_func(Library lib);
#endif
