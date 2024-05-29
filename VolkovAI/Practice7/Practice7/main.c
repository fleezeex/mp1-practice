#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Library.h"


int main(int argc, char** argv)
{    
    char* infilename;
    Library Lib;

    setlocale(LC_ALL, "Russian");
    if (argc < 2) {
        printf("Некорректный ввод. Вы не ввели место хранения базы данных.\n");
        return 1;
    }
    infilename = argv[1];
    read(infilename, &Lib);
    menu(&Lib);
    deallocateMemory(&Lib);
    return 0;
}
