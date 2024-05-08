#include <locale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "Library.h"
using namespace std;


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    if (argc < 2) {
        printf("Некорректный ввод. Вы не ввели место хранения базы данных.\n");
        return 1;
    }
    char* infilename = argv[1];
    std::ifstream in;
    std::ofstream out;
    Library Lib;

    in.open(infilename);
    in >> Lib;
    for (int a = 0; a < Lib.ncontinents; a++) {
        in >> Lib.continents[a];
        for (int b = 0; b < Lib.continents[a].ncountries; b++) {
            in >> Lib.continents[a].countries[b];
            for (int c = 0; c < Lib.continents[a].countries[b].nregions; c++) {
                in >> Lib.continents[a].countries[b].regions[c];
                for (int d = 0; d < Lib.continents[a].countries[b].regions[c].ncities; d++) {
                    in >> Lib.continents[a].countries[b].regions[c].cities[d];
                }
            }
        }
    }

    printf("lol");

    return 0;
}
