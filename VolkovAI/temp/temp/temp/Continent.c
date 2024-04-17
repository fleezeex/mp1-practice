#include "Continent.h"

void continents_func(Country* Countries, Continent* Continents, int numCities, int numVillages, int numCountries, int numContinents) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int population = 0;
    int flag = 0;
    printf("����������, ������� �������� ����������: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numContinents; i++) {
        if (strcmp(Continents[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    printf("������, �������� � ������ ������: ");
    for (int a = 0; a < Continents[flag].ncountries; a++) {
        printf("%s", Continents[flag].countries[a].name);
        population += Continents[flag].countries[a].population;
    }
    printf("\n����������� ��������� �� ����������: %d �������. \n", population);
}