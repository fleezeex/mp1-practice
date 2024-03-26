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

void oblasti(City* Cities, int numCities) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int c = 0;
    int population = 0;
    float square = 0;
    printf("Пожалуйста, введите название регион: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCities; i++) {
        if (strcmp(Cities[i].region, name) == 0) {
            c++;
        }
    }
    if (c == 0) {
        printf("Данный регион не была найден.");
        abort();
    }
    printf("Города, входящие в состав регион: ");
    for (int i = 0; i < numCities; i++) {
        if (strcmp(Cities[i].region, name) == 0) {
            if (c != 1) {
                printf("%s, ", Cities[i].name);
                c--;
            }
            else {
                printf("%s. \n", Cities[i].name);
            }
            population += Cities[i].population;
            square += Cities[i].square;
        }
    }
    printf("Численность населения: %d человек.\n", population);
    printf("Площадь: %.2f квадратных километров.", square);
}