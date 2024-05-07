#include <locale>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Library.h"
using namespace std;

void read(const char* infilename, Library Lib) {
	std::ifstream in;
	std::ofstream out;

    in.open(infilename);
    in >> Lib;
    for (int a = 0; a < Lib.ncontinents; a++) {
        in >> Lib.continents[a];
    }
}