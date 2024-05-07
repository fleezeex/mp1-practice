#include "Library.h"

void countries_func(Library Lib) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int flag = -1;
    int temp = 0;
    int cities_population = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("Пожалуйста, введите название страны: ");
    scanf("%[^\t\n]", &name);

    for (a = 0; a < Lib.ncontinents; a++) {
        for (b = 0; b < Lib.continents[a].ncountries; b++) {
            if (strcmp(name, Lib.continents[a].countries[b].name) == 0) {
                temp = Lib.continents[a].countries[b].nregions;
                flag = b;
                printf("Регионы, входящие в состав страны: ");
                for (c = 0; c < Lib.continents[a].countries[b].nregions; c++) {
                    if (temp == 1) {
                        printf("%s. \n", Lib.continents[a].countries[b].regions[c].name);
                    }
                    else {
                        printf("%s, ", Lib.continents[a].countries[b].regions[c].name);
                    }
                    temp--;
                    for (d = 0; d < Lib.continents[a].countries[b].regions[c].ncities; d++) {
                        cities_population += Lib.continents[a].countries[b].regions[c].cities[d].population;
                    }
                }
                if (Lib.continents[a].countries[b].form == 0) {
                    printf("Форма правления - монархия. \n");
                }
                if (Lib.continents[a].countries[b].form == 1) {
                    printf("Форма правления - республика. \n");
                }
                printf("Столица страны: %s. \n", Lib.continents[a].countries[b].capital);
                printf("Площадь страны: %.2f квадратных километров. \n", Lib.continents[a].countries[b].square);
                printf("Численность населения: %d человек. \n", Lib.continents[a].countries[b].population);
                printf("Процент городского населения: %lf%%.\n", 100 - (double)cities_population / ((double)Lib.continents[a].countries[b].population));
            }
        }
    }

    if (flag == -1) {
        printf("Название страны было введено некорректно или страна отсутствует в базе данных.");
        abort();
    }
}