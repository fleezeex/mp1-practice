#include "dop3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read(const char* infilename, City* Cities, Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents) {
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
            fscanf(f, "%s | %s | %s | %d | %f | %s \n", Cities[i + numCities].name, Cities[i + numCities].coor1, Cities[i + numCities].coor2, &Cities[i + numCities].population, &Cities[i + numCities].square, Cities[i + numCities].region);
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
    if (numCountries > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numCountries; i++) {
            fscanf(f, "%s | %d | %s | %s | %s \n", Countries[i].name, &Countries[i].numofregions, Countries[i].region_temp, Countries[i].form_of_government, Countries[i].capital);
            char* temp = strtok(Countries[i].region_temp, "/");
            while (temp != NULL)
            {
                for (int a = 0; a < Countries[i].numofregions; a++) {
                    Countries[i].regions[a] = temp;
                    temp = strtok(NULL, "/");
                    for (int q = 0; q < strlen(Countries[i].regions[a]); q++) {
                        if (Countries[i].regions[a][q] == '_') {
                            Countries[i].regions[a][q] = ' ';
                        }
                    }
                }
            }
        }
    }
    if (numContinents > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numContinents; i++) {
            fscanf(f, "%s | %d | %s \n", Continents[i].name, &Continents[i].numofcountries, Continents[i].temp_countries);
            char* temp = strtok(Continents[i].temp_countries, "/");
            while (temp != NULL)
            {
                for (int a = 0; a < Continents[i].numofcountries; a++) {
                    Continents[i].countries[a] = temp;
                    temp = strtok(NULL, "/");
                    for (int q = 0; q < strlen(Continents[i].countries[a]); q++) {
                        if (Continents[i].countries[a][q] == '_') {
                            Continents[i].countries[a][q] = ' ';
                        }
                    }
                }
            }
            for (int q = 0; q < strlen(Continents[i].name); q++) {
                if (Continents[i].name[q] == '_') {
                    Continents[i].name[q] = ' ';
                }
            }
        }
    }
    fclose(f);
}


void continents_func(City* Cities, Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int cities_population = 0;
    int villages_population = 0;
    float square = 0;
    printf("Пожалуйста, введите название материка: ");
    scanf("%[^\t\n]", &name);
    for (int a = 0; a < numContinents; a++)
        if (strcmp(Continents[a].name, name) == 0) {
            for (int b = 0; b < Continents[a].numofcountries; b++) {
                for (int c = 0; c < numCountries; c++)
                    if (strcmp(Countries[c].name, Continents[a].countries[b]) == 0) {
                        for (int d = 0; d < Countries[c].numofregions; d++) {
                            for (int e = 0; e < numCities; e++) {
                                if (strcmp(Cities[e].region, Countries[c].regions[d]) == 0) {
                                    cities_population += Cities[d].population;
                                    square += Cities[d].square;
                                }
                            }
                            for (int d = numCities; d < numCities + numVillages; d++) {
                                if (strcmp(Cities[d].region, Countries[b].regions[a]) == 0) {
                                    villages_population += Cities[d].population;
                                    square += Cities[d].square;
                                }
                            }
                        }
                    }
            }
        }
    printf("Площадь: %.2f квадратных километров.\nЧисленность населения: %d человек, из них сельского: %d человек. \n", square, cities_population + villages_population, villages_population);
    if (villages_population > 0) {
        printf("Процент сельского населения: %lf%%.\n", (double)villages_population / ((double)cities_population + (double)villages_population));
    }
}