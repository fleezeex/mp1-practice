#ifndef CONTINENT
#define CONTINENT
#include "Country.h"

class Continent
{
    private:
    string name;
    int ncountries;
    Country* countries;

    public:
    Continent();
    Continent(string name, int ncountries);
    Continent(const Continent& continent);
    ~Continent();

    friend std::ifstream& operator>>(std::ifstream& in, Continent& continent)
    {
        string temp;
        char* buffer;
        char* name;
        int ncountries;
       
        in >> temp;
        
        buffer = strtok (const_cast<char*> (temp.c_str()), ";");
        name = buffer;
        buffer = strtok (NULL, ";");
        ncountries = atoi(buffer);
        Continent(name, ncountries);
        free(buffer);
        free(name);
        return in;
    }
};

std::istream& operator>>(std::istream& in, Country& country);
//void countries_func(Library lib);
#endif
