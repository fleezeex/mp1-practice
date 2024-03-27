#include "dop.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read(const char* infilename, City* Cities, int numCities, int numVillages) {
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    fscanf(f, "%*[^\n]\n");
    fscanf(f, "%*[^\n]\n");

    for (int i = 0; i < numCities; i++) {
        fscanf(f, "%s | %s | %s | %d | %f | %s \n", Cities[i].name, Cities[i].coor1, Cities[i].coor2, &Cities[i].population, &Cities[i].square, Cities[i].region);
        {
            for (int a = 0; a < strlen(Cities[i].name); a++) {
                if (Cities[i].name[a] == '_') {
                    Cities[i].name[a] = ' ';
                    break;
                }
            }
            for (int a = 0; a < strlen(Cities[i].region); a++) {
                if (Cities[i].region[a] == '_') {
                    Cities[i].region[a] = ' ';
                    break;
                }
            }
        }
        printf("%s | %s | %s | %d | %.1f | %s \n", Cities[i].name, Cities[i].coor1, Cities[i].coor2, Cities[i].population, Cities[i].square, Cities[i].region);
    }
    if (numVillages > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numVillages; i++) {
            fscanf(f, "%s | %s | %s | %d | %f | %s \n", Cities[i+numCities].name, Cities[i + numCities].coor1, Cities[i + numCities].coor2, &Cities[i + numCities].population, &Cities[i + numCities].square, Cities[i + numCities].region);
            {
                for (int a = 0; a < strlen(Cities[i + numCities].name); a++) {
                    if (Cities[i + numCities].name[a] == '_') {
                        Cities[i + numCities].name[a] = ' ';
                        break;
                    }
                }
                for (int a = 0; a < strlen(Cities[i + numCities].region); a++) {
                    if (Cities[i + numCities].region[a] == '_') {
                        Cities[i + numCities].region[a] = ' ';
                        break;
                    }
                }
            }
            printf("%s | %s | %s | %d | %.1f | %s \n", Cities[i + numCities].name, Cities[i + numCities].coor1, Cities[i + numCities].coor2, Cities[i + numCities].population, Cities[i + numCities].square, Cities[i + numCities].region);
        }
    }
    fclose(f);

}

int numof(const char* infilename, int numcities) {
    int res = 0;
    char garbage[15];
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    if (numcities > 0) {
        for (int i = 0; i < numcities + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    fscanf(f, "%s %d", garbage, &res);
    fclose(f);
    return res;
}

void oblasti(City* Cities, int numCities, int numVillages) {
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
    for (int i = cities_counter; i < cities_counter+numVillages; i++) {
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
    printf("Площадь: %.2f квадратных километров.", square);
}