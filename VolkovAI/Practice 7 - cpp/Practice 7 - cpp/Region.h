#ifndef REGION
#define REGION
#include "City.h"

class Region
{
    private:
    string name;
    int ncities;
    City* cities;
    City capital;
    int population;

    public:
    Region();
    Region(string name, int population, string capitalname, int ncities);
    Region(const Region& region);
    ~Region();

    City& get_city(int index)  {
        return cities[index];
    }

    string get_name() const {
        return this->name;
    }

    int get_ncities() const {
        return this->ncities;
    }

    const Region& operator= (const Region&);
    friend std::ifstream& operator>>(std::ifstream& in, Region& region);
    friend std::ostream& operator<< (std::ostream& out, Region& region);
};
//void regions_func(Library lib);
#endif
