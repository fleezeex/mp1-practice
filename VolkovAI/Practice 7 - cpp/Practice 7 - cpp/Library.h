#ifndef LIBRARY
#define LIBRARY
#include "Continent.h"

class Library
{
    private:
    int ncontinents;
    Continent* continents;

    public:
    Library();
    Library(int ncontinents);
    Library(const Library& lib);
    ~Library();
    
    int get_ncontinents() const {
        return ncontinents;
    }

     Continent& get_continents(int index)  {
        return continents[index];
    }

    const Library& operator= (const Library&);

    friend std::ifstream& operator>>(std::ifstream& in, Library& Lib)
    {
        in >> Lib.ncontinents;
        if (Lib.continents != nullptr) {
            delete[] Lib.continents;
        }
        Lib.continents = new Continent[Lib.ncontinents];
        for (int a = 0; a < Lib.ncontinents; a++) {
            in >> Lib.continents[a];
            for (int b = 0; b < Lib.continents[a].get_ncountries(); b++) {
                in >> Lib.continents[a].get_country(b);
                for (int c = 0; c < Lib.continents[a].get_country(b).get_nregions(); c++) {
                    in >> Lib.continents[a].get_country(b).get_region(c);
                    for (int d = 0; d < Lib.continents[a].get_country(b).get_region(c).get_ncities(); d++) {
                        in >> Lib.continents[a].get_country(b).get_region(c).get_city(d);
                    }
                }
            }
        }
        return in;
    }

    friend void cities_func(Library* lib);
};

std::istream& operator>>(std::istream& in, Library& lib);

void menu(Library* Lib);
void cities_func(Library* lib);
void cities_func(Library* Lib);
void regions_func(Library* Lib);
void countries_func(Library* Lib);
void continents_func(Library* Lib);

#endif
