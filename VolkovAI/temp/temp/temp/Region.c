#include "Region.h"

void regions_func(City* Cities, Region* Regions, int numCities, int numVillages, int numRegions) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_population = 0;
    int villages_population = 0;
    float square = 0;
    int flag = 0;
    printf("Пожалуйста, введите название региона: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numRegions; i++) {
        if (strcmp(Regions[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    /*
    if (flag == 0) {
        printf("Название региона было введено некорректно или регион отсутствует в базе данных.");
        abort();
    }
    */
    printf("Города, входящие в состав региона: ");
    for (int a = 0; a < Regions[flag].ncities; a++) {
        for (int b = 0; b < numCities; b++) {
            if (strcmp(Regions[flag].cities[a].name, Cities[b].name) == 0) {
                printf("%s", Cities[b].name);
            }
        }
    }
    printf("Деревни, входящие в состав региона: ");
    for (int a = 0; a < Regions[flag].ncities; a++) {
        for (int b = numCities; b < numCities+numVillages; b++) {
            if (strcmp(Regions[flag].cities[a].name, Cities[b].name) == 0) {
                printf("%s", Cities[b].name);
                villages_population += Cities[b].population;
            }
        }
    }
    printf("Численность населения: %d человек.\n", Regions[flag].population);
    printf("Процент городского населения: %lf%%.\n", 100 - ((double)villages_population / ((double)Regions[flag].population)));
}