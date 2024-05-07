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
    private:
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

    friend std::ifstream& operator>>(std::ifstream& in, Country& country)
    {
        char* temp;
        char* buffer;
        in >> temp;
        
        buffer = strtok (temp, ";");
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
        buffer = strtok (NULL, ";");
        country.nregions = atoi(buffer);
        return in;
    }
};

std::istream& operator>>(std::istream& in, Country& country);
//void countries_func(Library lib);
#endif
