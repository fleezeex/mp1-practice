#include "Country.h"

void countries_func(City* Cities, Country* Countries, int numCities, int numVillages, int numCountries) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int villages_population = 0;
    float square = 0;
    int flag = 0;
    printf("����������, ������� �������� ������: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCountries; i++) {
        if (strcmp(Countries[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    printf("�������, �������� � ������ ������: ");
    for (int a = 0; a < Countries[flag].nregions; a++) {
        printf("%s", Countries[flag].regions[a]);
    }
    for (int q = 0; q < Countries[flag].nregions; q++) {
        for (int a = 0; a < Countries[flag].regions[q].ncities; a++) {
            for (int b = numCities; b < numCities + numVillages; b++) {
                if (strcmp(Countries[flag].regions[q].cities[a].name, Cities[b].name) == 0) {
                    villages_population += Cities[b].population;
                }
            }
        }
    }
    printf("����������� ���������: %d �������. \n", Countries[flag].population);
    printf("������� ���������� ���������: %lf%%.\n", 100 - ((double)villages_population / ((double)Countries[flag].population)));
}