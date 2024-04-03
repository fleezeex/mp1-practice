#include "dop2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void countries_func(City* Cities, Country* Countries, int numCities, int numVillages, int numCountries) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_population = 0;
    int villages_population = 0;
    float square = 0;
    printf("Пожалуйста, введите название страны: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCountries; i++) {
        if (strcmp(Countries[i].name, name) == 0) {
            for (int a = 0; a < Countries[i].numofregions; a++) {
                for (int b = 0; b < numCities; b++) {
                    if (strcmp(Cities[b].region, Countries[i].regions[a]) == 0) {
                        cities_population += Cities[b].population;
                        square += Cities[b].square;
                    }
                }
                for (int c = numCities; c < numCities + numVillages; c++) {
                    if (strcmp(Cities[c].region, Countries[i].regions[a]) == 0) {
                        villages_population += Cities[c].population;
                        square += Cities[c].square;
                    }
                }
            }
            printf("Столица: %s\n", Countries[i].capital);
        }
    }
    printf("Площадь: %.2f квадратных километров.\nЧисленность населения: %d человек, из них сельского: %d человек. \n", square, cities_population + villages_population, villages_population);
    if (villages_population > 0) {
        printf("Процент сельского населения: %lf%%.\n", ((double)villages_population / ((double)cities_population + (double)villages_population)) * 100);
    }
}