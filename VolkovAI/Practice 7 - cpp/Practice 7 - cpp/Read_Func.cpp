#include <locale>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Library.h"
using namespace std;

void read(const char* infilename, Library* Lib) {
	std::ifstream in;
	std::ofstream out;

    in.open(infilename);
    in >> Lib;
    for (int a = 0; a < Lib->ncontinents; a++) {
        in >> Lib->continents[a];
        for (int b = 0; b < Lib->continents[a].ncountries; b++) {
            in >> Lib->continents[a].countries[b];
            for (int c = 0; c < Lib->continents[a].countries[b].nregions; c++) {
                in >> Lib->continents[a].countries[b].regions[c];
                for (int d = 0; d < Lib->continents[a].countries[b].regions[c].ncities; d++) {
                    in >> Lib->continents[a].countries[b].regions[c].cities[d];
                }
            }
        }
    }
}