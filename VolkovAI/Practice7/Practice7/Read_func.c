#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Library.h"

void read(const char* infilename, Library* Lib) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    char temp[buffer_size];
    char* buffer = malloc(sizeof(char) * buffer_size);

    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }

    fgets(temp, buffer_size, f);
    Lib->ncontinents = atoi(temp);
    Lib->continents = malloc(Lib->ncontinents * sizeof(Continent));

    for (a = 0; a < Lib->ncontinents; a++) {
        fgets(temp, buffer_size, f);
        char* buffer = strtok(temp, ";");
        strcpy(Lib->continents[a].name, buffer);
        buffer = strtok(NULL, ";");
        Lib->continents[a].ncountries = atoi(buffer);
        Lib->continents[a].countries = malloc(Lib->continents[a].ncountries * sizeof(Country));


        for (b = 0; b < Lib->continents[a].ncountries; b++) {
            fgets(temp, buffer_size, f);
            char* buffer = strtok(temp, ";");
            strcpy(Lib->continents[a].countries[b].name, buffer);
            buffer = strtok(NULL, ";");
            if (strcmp(buffer, "монархия") == 0) {
                Lib->continents[a].countries[b].form = 0;
            }
            if (strcmp(buffer, "республика") == 0) {
                Lib->continents[a].countries[b].form = 1;
            }
            buffer = strtok(NULL, ";");
            strcpy(Lib->continents[a].countries[b].capital.name, buffer);
            buffer = strtok(NULL, ";");
            Lib->continents[a].countries[b].square = atoi(buffer);
            buffer = strtok(NULL, ";");
            Lib->continents[a].countries[b].population = atoi(buffer);
            buffer = strtok(NULL, ";");
            Lib->continents[a].countries[b].nregions = atoi(buffer);
            Lib->continents[a].countries[b].regions = malloc(Lib->continents[a].countries[b].nregions * sizeof(Region));
            for (c = 0; c < Lib->continents[a].countries[b].nregions; c++) {
                fgets(temp, buffer_size, f);
                char* buffer = strtok(temp, ";");
                strcpy(Lib->continents[a].countries[b].regions[c].name, buffer);
                buffer = strtok(NULL, ";");
                Lib->continents[a].countries[b].regions[c].population = atoi(buffer);
                buffer = strtok(NULL, ";");
                strcpy(Lib->continents[a].countries[b].regions[c].capital.name, buffer);
                buffer = strtok(NULL, ";");
                Lib->continents[a].countries[b].regions[c].ncities = atoi(buffer);
                Lib->continents[a].countries[b].regions[c].cities = malloc(Lib->continents[a].countries[b].regions[c].ncities * sizeof(City));
                for (d = 0; d < Lib->continents[a].countries[b].regions[c].ncities; d++) {
                    fgets(temp, buffer_size, f);
                    char* buffer = strtok(temp, ";");
                    strcpy(Lib->continents[a].countries[b].regions[c].cities[d].name, buffer);
                    buffer = strtok(NULL, ";");
                    strcpy(Lib->continents[a].countries[b].regions[c].cities[d].coor1, buffer);
                    buffer = strtok(NULL, ";");
                    strcpy(Lib->continents[a].countries[b].regions[c].cities[d].coor2, buffer);
                    buffer = strtok(NULL, ";");
                    Lib->continents[a].countries[b].regions[c].cities[d].population = atoi(buffer);
                    if (strcmp(Lib->continents[a].countries[b].regions[c].cities[d].name, Lib->continents[a].countries[b].regions[c].capital.name) == 0) {
                        Lib->continents[a].countries[b].regions[c].capital = Lib->continents[a].countries[b].regions[c].cities[d];
                    }
                    if (strcmp(Lib->continents[a].countries[b].regions[c].cities[d].name, Lib->continents[a].countries[b].capital.name) == 0) {
                        Lib->continents[a].countries[b].capital = Lib->continents[a].countries[b].regions[c].cities[d];
                    }
                }
            }
        }
    }
    free(buffer);
}

void deallocateMemory(Library* Lib) {
    int a = 0;
    int b = 0;
    int c = 0;
    for (a = 0; a < Lib->ncontinents; a++) {
        for (b = 0; b < Lib->continents[a].ncountries; b++) {
            for (c = 0; c < Lib->continents[a].countries[b].nregions; c++) {
                free(Lib->continents[a].countries[b].regions[c].cities);
            }
            free(Lib->continents[a].countries[b].regions);
        }
        free(Lib->continents[a].countries);
    }
    free(Lib->continents);
}
