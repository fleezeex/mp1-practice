#include "Library.h"

void cities_func(Library* Lib) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int flag = -1;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("Пожалуйста, введите название города/деревни: ");
    scanf("%[^\t\n]", &name);

    for (a = 0; a < Lib->ncontinents; a++) {
        for (b = 0; b < Lib->continents[a].ncountries; b++) {
            for (c = 0; c < Lib->continents[a].countries[b].nregions; c++) {
                for (d = 0; d < Lib->continents[a].countries[b].regions[c].ncities; d++) {
                    if (strcmp(name, Lib->continents[a].countries[b].regions[c].cities[d].name) == 0) {
                        flag = d;
                        printf("Координаты: %s %s\n", Lib->continents[a].countries[b].regions[c].cities[d].coor1, Lib->continents[a].countries[b].regions[c].cities[d].coor2);
                        printf("Население: %d человек.\n", Lib->continents[a].countries[b].regions[c].cities[d].population);
                    }
                }
            }
        }
    }

    if (flag == -1) {
        printf("Название города было введено некорректно или город отсутствует в базе данных.");
        abort();
    }
}