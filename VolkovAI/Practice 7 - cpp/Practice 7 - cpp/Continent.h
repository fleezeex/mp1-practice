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

    string get_name() const {
        return this->name;
    }

    Country& get_country(int index)  {
        return countries[index];
    }

    int get_ncountries() const {
        return this->ncountries;
    }

    const Continent& operator= (const Continent&);

    friend std::ifstream& operator>>(std::ifstream& in, Continent& continent);
    friend std::ostream& operator<< (std::ostream& out, Continent& continent);
};

//void countries_func(Library lib);
#endif
