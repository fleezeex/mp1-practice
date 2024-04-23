#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Continent.h"

int numof(const char* infilename, int numCities, int numRegions, int numCountries) {
    int res = 0;
    char garbage[20];
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
    if (numRegions > 0) {
        for (int i = numCities; i < numCities + numRegions + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    if (numCountries > 0) {
        for (int i = numCities + numRegions; i < numCities + numRegions + numCountries + 2; i++) {
            fscanf(f, "%*[^\n]\n");
        }
    }
    fscanf(f, "%s %d", garbage, &res);
    fclose(f);
    return res;
}

void read(const char* infilename, City* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numRegions, int numCountries, int numContinents) {
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    int cities_temp = 0;
    int countries_temp = 0;
    int continents_temp = 0;
    int num_temp = 0;
    char temp[buffer_size];
    char* buffer = malloc(sizeof(char) * buffer_size);
    char buffer2[buffer_size];
    char* temp2 = malloc(sizeof(char) * buffer_size);

    fscanf(f, "%*[^\n]\n");
    fscanf(f, "%*[^\n]\n");
    if (numCities > 0) {
        for (int i = 0; i < numCities ; i++) {
            num_temp = 0;
            fgets(temp, buffer_size, f);
            char* buffer = strtok(temp, "|");
            while (buffer != NULL)
            {
                if (num_temp >= 1) {
                    memmove(buffer, buffer + 1, strlen(buffer));
                }
                buffer[strlen(buffer) - 1] = 0;
                if (num_temp == 0) {
                    strcpy(Cities[i].name, buffer);
                }
                if (num_temp == 1) {
                    strcpy(Cities[i].coor1, buffer);
                }
                if (num_temp == 2) {
                    strcpy(Cities[i].coor2, buffer);
                }
                if (num_temp == 3) {
                    Cities[i].population = atoi(buffer);
                }
                num_temp++;
                buffer = strtok(NULL, "|");
            }
        }
    }
    if (numRegions > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numRegions; i++) {
            cities_temp, num_temp = 0, 0;
            fgets(temp, buffer_size, f);
            char* buffer = strtok(temp, "|");
            while (buffer != NULL)
            {
                if (num_temp >= 1) {
                    memmove(buffer, buffer + 1, strlen(buffer));
                }
                buffer[strlen(buffer) - 1] = 0;

                if (num_temp == 0) {
                    strcpy(Regions[i].name, buffer);
                }

                if (num_temp == 1) {
                    Regions[i].ncities = atoi(buffer);
                }

                if (num_temp == 2) {
                    Regions[i].population = atoi(buffer);
                }

                if (num_temp == 3) {
                    for (int a = 0; a < numCities; a++) {
                        if (strcmp(buffer, Cities[a].name) == 0) {
                            Regions[i].capital = Cities[a];
                        }
                    }
                }

                if (num_temp == 4) {
                    cities_temp = 0;
                    strcpy(buffer2, buffer);
                    strcpy(temp2, buffer);
                    char* temp2 = strtok(buffer2, "/");
                    while (temp2 != NULL) {
                        for (int a = 0; a < numCities; a++) {
                            if (strcmp(temp2, Cities[a].name) == 0) {
                                Regions[i].cities[cities_temp] = Cities[a];
                                cities_temp++;
                            }
                        }
                        temp2 = strtok(NULL, "/");
                    }
                }

                num_temp++;
                buffer = strtok(NULL, "|");
            }
        }
    }
    if (numCountries > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numCountries; i++) {
            countries_temp, num_temp = 0, 0;
            fgets(temp, buffer_size, f);
            char* buffer = strtok(temp, "|");
            while (buffer != NULL) {
                if (num_temp >= 1) {
                    memmove(buffer, buffer + 1, strlen(buffer));
                }
                buffer[strlen(buffer) - 1] = 0;

                if (num_temp == 0) {
                    strcpy(Countries[i].name, buffer);
                }

                if (num_temp == 1) {
                    if (strcmp(buffer, "монархия") == 0) {
                        Countries[i].form = 0;
                    }
                    if (strcmp(buffer, "республика") == 0) {
                        Countries[i].form = 1;
                    }

                }

                if (num_temp == 2) {
                    for (int a = 0; a < numCities; a++) {
                        if (strcmp(buffer, Cities[a].name) == 0) {
                            Countries[i].capital = Cities[a];
                        }
                    }
                }

                if (num_temp == 3) {
                    Countries[i].square = atoi(buffer);
                }

                if (num_temp == 4) {
                    Countries[i].population = atoi(buffer);
                }

                if (num_temp == 5) {
                    Countries[i].nregions = atoi(buffer);
                }

                if (num_temp == 6) {
                    countries_temp = 0;
                    strcpy(buffer2, buffer);
                    strcpy(temp2, buffer);
                    char* temp2 = strtok(buffer2, "/");
                    while (temp2 != NULL) {
                        for (int a = 0; a < numRegions; a++) {
                            if (strcmp(temp2, Regions[a].name) == 0) {
                                Countries[i].regions[countries_temp] = Regions[a];
                                countries_temp++;
                            }
                        }
                        temp2 = strtok(NULL, "/");
                    }
                }

                num_temp++;
                buffer = strtok(NULL, "|");
            }
        }
    }
    if (numContinents > 0) {
        fscanf(f, "%*[^\n]\n");
        fscanf(f, "%*[^\n]\n");
        for (int i = 0; i < numContinents; i++) {
            continents_temp, num_temp = 0, 0;
            fgets(temp, buffer_size, f);
            char* buffer = strtok(temp, "|");
            while (buffer != NULL)
            {
                if (num_temp >= 1) {
                    memmove(buffer, buffer + 1, strlen(buffer));
                }
                buffer[strlen(buffer) - 1] = 0;

                if (num_temp == 0) {
                    strcpy(Continents[i].name, buffer);
                }

                if (num_temp == 1) {
                    Continents[i].ncountries = atoi(buffer);
                }

                if (num_temp == 2) {
                    continents_temp = 0;
                    strcpy(buffer2, buffer);
                    strcpy(temp2, buffer);
                    char* temp2 = strtok(buffer2, "/");
                    while (temp2 != NULL) {
                        for (int a = 0; a < numCountries; a++) {
                            if (strcmp(temp2, Countries[a].name) == 0) {
                                Continents[i].countries[continents_temp] = Countries[a];
                                continents_temp++;
                            }
                        }
                        temp2 = strtok(NULL, "/");
                    }
                }

                num_temp++;
                buffer = strtok(NULL, "|");
            }
        }
    }
    free(buffer);
    free(temp2);
}