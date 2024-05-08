#ifndef CONTINENT
#define CONTINENT
#include "Country.h"

class Continent
{
    public:
    string name;
    int ncountries;
    Country* countries;

    public:
    Continent();
    Continent(string name, int ncountries);
    Continent(const Continent& continent);
    ~Continent();

    const Continent& operator= (const Continent&);

    friend std::ifstream& operator>>(std::ifstream& in, Continent& continent)
    {
        string temp;
        char* buffer;
       
        in >> temp;
        
        buffer = strtok (const_cast<char*> (temp.c_str()), ";");
        continent.name = buffer;
        buffer = strtok (NULL, ";");
        continent.ncountries = atoi(buffer);
        continent.countries = new Country[continent.ncountries];
        return in;
    }
};

std::istream& operator>>(std::istream& in, Country& country);
//void countries_func(Library lib);
#endif
