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

    const Region& operator= (const Region&);
    friend std::ifstream& operator>>(std::ifstream& in, Region& region)
    {
        string temp;
        char* buffer;
        getline(in, temp);
        
        buffer = strtok(const_cast<char*> (temp.c_str()), ";");
        region.name = buffer;
        buffer = strtok (NULL, ";");
        region.population = atoi(buffer);
        buffer = strtok (NULL, ";");
        region.capital.name = buffer;
        buffer = strtok (NULL, ";");
        region.ncities = atoi(buffer);
        region.cities = new City[region.ncities];
        return in;
    }
};

std::istream& operator>>(std::istream& in, Region& region);
//void regions_func(Library lib);
#endif
