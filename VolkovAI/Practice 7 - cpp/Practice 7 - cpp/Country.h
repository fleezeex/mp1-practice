#ifndef COUNTRY
#define COUNTRY
#include "Region.h"

typedef enum {
    Monarchy = 0,
    Republic = 1
} GovermentForm;

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

    string get_name() const {
        return this->name;
    }

    Region& get_region(int index)  {
        return regions[index];
    }

    int get_nregions() const {
        return this->nregions;
    }

    int get_population() const {
        return this->population;
    }

    const Country& operator= (const Country&);

    friend std::ifstream& operator>>(std::ifstream& in, Country& country);
    friend std::ostream& operator<< (std::ostream& out, Country& country);
};

//void countries_func(Library lib);
#endif
