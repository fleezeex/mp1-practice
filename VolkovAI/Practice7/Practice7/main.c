#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Library.h"


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    char* infilename;
    if (argc < 2) {
        printf("Некорректный ввод. Вы не ввели место хранения базы данных.\n");
        return 1;
    }
    infilename = argv[1];
    int numCities = 0, numRegions = 0, numCountries = 0, numContinents = 0;
    int c;

    Library Lib;

    read(infilename, &Lib);

    menu(&Lib);

    deallocateMemory(&Lib);

    return 0;
}
