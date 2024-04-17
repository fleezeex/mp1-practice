#include "dop2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int numof(const char* infilename, int numCities, int numVillages, int numCountries) {
    int res = 0;
    char garbage[15];
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    if (numCities > 0) {
        for (int i = 0; i < numCities + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    if (numVillages > 0) {
        for (int i = numCities; i < numCities+numVillages + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    if (numCountries > 0) {
        for (int i = numCities+numVillages; i < numCountries + numCities + numVillages + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    fscanf(f, "%s %d", garbage, &res);
    fclose(f);
    return res;
}

void cities_func(City* Cities, int numCities, int numVillages) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    printf("Пожалуйста, введите название города/деревни: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCities+numVillages; i++) {
        if (strcmp(Cities[i].name, name) == 0) {
            printf("Координаты: %s %s\n", Cities[i].coor1, Cities[i].coor2);
            printf("Население: %d человек\n", Cities[i].population);
            printf("Площадь: %f квадратных километров.\n", Cities[i].square);
            printf("Регион: %s\n", Cities[i].region);
        }
    }
}

void regions(City* Cities, int numCities, int numVillages) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_counter = 0;
    int villages_counter = 0;
    int cities_population = 0;
    int villages_population = 0;
    float square = 0;
    printf("Пожалуйста, введите название региона: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCities; i++) {
        if (strcmp(Cities[i].region, name) == 0) {
            cities_counter++;
        }
    }
    for (int i = numCities; i < numCities+numVillages; i++) {
        if (strcmp(Cities[i].region, name) == 0) {
            villages_counter++;
        }
    }
    if (cities_counter == 0) {
        printf("Данный регион не была найден.");
        abort();
    }
    printf("Города, входящие в состав региона: ");
    for (int i = 0; i < numCities; i++) {
        if (strcmp(Cities[i].region, name) == 0) {
            if (cities_counter != 1) {
                printf("%s, ", Cities[i].name);
                cities_counter--;
            }
            else {
                printf("%s. \n", Cities[i].name);
            }
            cities_population += Cities[i].population;
            square += Cities[i].square;
        }
    }
    if (villages_counter > 0) {
        printf("Деревни, входящие в состав региона: ");
        for (int i = numCities - 1; i < numCities + numVillages; i++) {
            if (strcmp(Cities[i].region, name) == 0) {
                if (cities_counter != 1) {
                    printf("%s, ", Cities[i].name);
                    cities_counter--;
                }
                else {
                    printf("%s. \n", Cities[i].name);
                }
                square += Cities[i].square;
                villages_population += Cities[i].population;
            }
        }
    }
    printf("Численность населения: %d человек.\n", cities_population+villages_population);
    if (villages_counter > 0) {
        printf("Процент сельского населения: %lf%%.\n", (double) villages_population / ((double)cities_population + (double) villages_population));
    }
    printf("Площадь: %.2f квадратных километров.\n", square);
}
