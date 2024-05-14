#include "Library.h"

void regions_func(Library* Lib) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_population = 0;
    int temp = 0;
    int flag = -1;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("Пожалуйста, введите название региона: ");
    scanf("%[^\t\n]", &name);

    for (a = 0; a < Lib->ncontinents; a++) {
        for (b = 0; b < Lib->continents[a].ncountries; b++) {
            for (c = 0; c < Lib->continents[a].countries[b].nregions; c++) {
                if (strcmp(name, Lib->continents[a].countries[b].regions[c].name) == 0) {
                    flag = c;
                    printf("Столица региона: %s.\n", Lib->continents[a].countries[b].regions[c].capital);
                    printf("Города, входящие в состав региона: ");
                    temp = Lib->continents[a].countries[b].regions[c].ncities;
                    for (d = 0; d < Lib->continents[a].countries[b].regions[c].ncities; d++) {
                        if (temp == 1) {
                            printf("%s. \n", Lib->continents[a].countries[b].regions[c].cities[d].name);
                        }
                        else {
                            printf("%s, ", Lib->continents[a].countries[b].regions[c].cities[d].name);
                        }
                        cities_population += Lib->continents[a].countries[b].regions[c].cities[d].population;
                        temp--;
                    }
                    printf("Численность населения: %d человек.\n", Lib->continents[a].countries[b].regions[c].population);
                    printf("Процент городского населения: %lf%%.\n", 100 - (double)cities_population / (double)Lib->continents[a].countries[b].regions[c].population);
                }
            }
        }
    }

    if (flag == -1) {
        printf("Название региона было введено некорректно или регион отсутствует в базе данных.");
        abort();
    }
}