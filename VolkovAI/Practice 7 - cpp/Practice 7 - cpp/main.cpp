#include <locale>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <windows.h> 
#include "Library.h"
using namespace std;


int main(int argc, char** argv)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (argc < 2) {
        printf("Некорректный ввод. Вы не ввели место хранения базы данных.\n");
        return 1;
    }
    char* infilename = argv[1];
    Library Lib;
    std::ifstream in;

    in.open(infilename);
    in >> Lib;

    menu(&Lib);


    return 0;
}
