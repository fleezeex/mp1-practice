#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Continent.h"

void menu(City* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numRegions, int numCountries, int numContinents) {
    int c;
    int num = 1000;
    printf("Справочник географа.\n");
    printf("Пожалуйста, выберите пункт, о котором бы Вы хотели узнать информацию. \n1. Города/деревни.\n2. Регионы.\n3. Страны.\n4. Материки.\n0. Завершение работы.\nВведите необходимый пункт: ");
    scanf("%d", &num);
    while ((c = getchar()) != '\n' && c != EOF);
    while (num != 0) {
        if (num == 1) {
            cities_func(Cities, numCities);
        }
        
        if (num == 2) {
            regions_func(Cities, Regions, numCities, numRegions);
        }
        
        if (num == 3) {
            countries_func(Cities, Countries, numCities, numCountries);
        }
        if (num == 4) {
            continents_func(Countries, Continents, numContinents);
        }
        printf("Пожалуйста, выберите пункт, о котором бы Вы хотели узнать информацию: ");
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}