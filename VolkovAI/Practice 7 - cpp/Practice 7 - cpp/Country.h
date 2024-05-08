#ifndef COUNTRY
#define COUNTRY
#include "Region.h"

enum class GovermentForm
{
    Monarchy,
    Republic
};

class Country
{
    public:
    string name;

    float square;
    int population;
    GovermentForm form;       
    City capital;

    int nregions;
    Region* regions;

    public:
    Country();
    Country(string name, GovermentForm form, string capitalname, int population, float square, int nregions);
    Country(const Country& country);
    ~Country();

    const Country& operator= (const Country&);

    friend std::ifstream& operator>>(std::ifstream& in, Country& country)
    {
        string temp;;
        char* buffer;
        in >> temp;
        
        buffer = strtok (const_cast<char*> (temp.c_str()), ";");
        country.name = buffer;
        buffer = strtok (NULL, ";");
        if (buffer == "республика") 
            country.form = GovermentForm::Republic;
        else if (buffer == "монархия")
            country.form = GovermentForm::Monarchy;
        buffer = strtok (NULL, ";");
        country.capital.name = buffer;
        buffer = strtok (NULL, ";");
        country.square = atof(buffer);
        buffer = strtok(NULL, ";");
        country.population = atof(buffer);
        buffer = strtok (NULL, ";");
        country.nregions = atoi(buffer);
        country.regions = new Region[country.nregions];
        return in;
    }
};

std::istream& operator>>(std::istream& in, Country& country);
//void countries_func(Library lib);
#endif
