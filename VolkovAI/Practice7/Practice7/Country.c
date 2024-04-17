#include "Country.h"

void countries_func(City* Cities, Country* Countries, int numCities, int numVillages, int numCountries) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int villages_population = 0;
    int flag = -1;
    int temp = 0;
    printf("Пожалуйста, введите название страны: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCountries; i++) {
        if (strcmp(Countries[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("Название страны было введено некорректно или страна отсутствует в базе данных.");
        abort();
    }
    temp = Countries[flag].nregions;
    for (int a = 0; a < Countries[flag].nregions; a++) {
        if (temp == Countries[flag].nregions) {
            printf("Регионы, входящие в состав страны: ");
                }
                if (temp == 1) {
                    printf("%s. \n", Countries[flag].regions[a]);
                }
                else {
                    printf("%s, ", Countries[flag].regions[a]);
                }
                temp--;
    }
    for (int q = 0; q < Countries[flag].nregions; q++) {
        for (int a = Countries[flag].regions[q].nvillages; a < Countries[flag].regions[q].ncities + Countries[flag].regions[q].nvillages; a++) {
            for (int b = numCities; b < numCities + numVillages; b++) {
                if (strcmp(Countries[flag].regions[q].cities[a].name, Cities[b].name) == 0) {
                    villages_population += Cities[b].population;
                }
            }
        }
    }
    if (Countries[flag].form == 0) {
        printf("Форма правления - монархия. \n");
    }
    if (Countries[flag].form == 1) {
        printf("Форма правления - республика. \n");
    }
    printf("Столица страны: %s. \n", Countries[flag].capital);
    printf("Площадь страны: %.2f квадратных километров. \n", Countries[flag].square);
    printf("Численность населения: %d человек. \n", Countries[flag].population);
    printf("Процент городского населения: %lf%%.\n", 100 - ((double)villages_population / ((double)Countries[flag].population)));
}