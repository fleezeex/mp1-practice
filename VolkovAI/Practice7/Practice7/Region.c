#include "Region.h"

void regions_func(City* Cities, Region* Regions, int numCities, int numRegions) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_population = 0;
    int temp = 0;
    int flag = -1;
    printf("Пожалуйста, введите название региона: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numRegions; i++) {
        if (strcmp(Regions[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("Название региона было введено некорректно или регион отсутствует в базе данных.");
        abort();
    }
    temp = Regions[flag].ncities;
    for (int a = 0; a < Regions[flag].ncities; a++) {
        for (int b = 0; b < numCities; b++) {
            if (strcmp(Regions[flag].cities[a].name, Cities[b].name) == 0) {
                if (temp == Regions[flag].ncities) {
                    printf("Города, входящие в состав региона: ");
                }
                if (temp == 1) {
                    printf("%s. \n", Cities[b].name);
                }
                else {
                    printf("%s, ", Cities[b].name);
                }
                cities_population += Cities[b].population;
                temp--;
            }
        }
    }
    printf("Численность населения: %d человек.\n", Regions[flag].population);
    printf("Процент городского населения: %lf%%.\n", 100 - (double)cities_population / ((double)Regions[flag].population));
}