#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"

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
        for (int i = numCities; i < numCities + numVillages + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    if (numCountries > 0) {
        for (int i = numCities + numVillages; i < numCountries + numCities + numVillages + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    fscanf(f, "%s %d", garbage, &res);
    fclose(f);
    return res;
}

void read(const char* infilename, City* Cities, Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents) {
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    fscanf(f, "%*[^\n]\n");
    fscanf(f, "%*[^\n]\n");

    for (int i = 0; i < numCities; i++) {
        fscanf(f, "%s | %s | %s | %d\n", Cities[i].name, Cities[i].coor1, Cities[i].coor2, &Cities[i].population);
        {
            for (int a = 0; a < strlen(Cities[i].name); a++) {
                if (Cities[i].name[a] == '_') {
                    Cities[i].name[a] = ' ';
                    break;
                }
            }
        }
        ///printf("%s | %s | %s | %d | %.1f | %s \n", Cities[i].name, Cities[i].coor1, Cities[i].coor2, Cities[i].population, Cities[i].square, Cities[i].region);
    }
    if (numVillages > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numVillages; i++) {
            fscanf(f, "%s | %s | %s | %d\n", Cities[i + numCities].name, Cities[i + numCities].coor1, Cities[i + numCities].coor2, &Cities[i + numCities].population);
            {
                for (int a = 0; a < strlen(Cities[i + numCities].name); a++) {
                    if (Cities[i + numCities].name[a] == '_') {
                        Cities[i + numCities].name[a] = ' ';
                        break;
                    }
                }
            }
            /// printf("%s | %s | %s | %d | %.1f | %s \n", Cities[i + numCities].name, Cities[i + numCities].coor1, Cities[i + numCities].coor2, Cities[i + numCities].population, Cities[i + numCities].square, Cities[i + numCities].region);
        }
    }
    if (numCountries > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numCountries; i++) {
            fscanf(f, "%s | %d | %s | %GovermentForm | %City \n", Countries[i].name, &Countries[i].nregions, Countries[i].regions_temp, Countries[i].form, Countries[i].capital);
            char* temp = strtok(Countries[i].region_temp, "/");
            while (temp != NULL)
            {
                for (int a = 0; a < Countries[i].numofregions; a++) {
                    Countries[i].regions[a] = temp;
                    temp = strtok(NULL, " | ");
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