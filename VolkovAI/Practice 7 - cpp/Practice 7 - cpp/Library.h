#ifndef LIBRARY
#define LIBRARY
#include "Continent.h"

class Library
{
    public:
    int ncontinents;
    Continent* continents;

    public:
    Library();
    Library(int ncontinents);
    Library(const Library& lib);
    ~Library();

    friend std::ifstream& operator>>(std::ifstream& in, Library& lib)
    {
        in >> lib.ncontinents;
        if (lib.continents != nullptr) {
            delete[] lib.continents;
        }
        Library(lib.ncontinents);
        return in;
    }
};

std::istream& operator>>(std::istream& in, Library& lib);
void read(const char* infilename, Library* Lib);
#endif
