#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Continent.h"

void menu(City* Cities, Region* Regions, Country* Countries, Continent* Continents, int numCities, int numVillages, int numRegions, int numCountries, int numContinents) {
    int c;
    int num = 1000;
    printf("���������� ��������.\n");
    printf("����������, �������� �����, � ������� �� �� ������ ������ ����������. \n1. ������/�������.\n2. �������.\n3. ������.\n4. ��������.\n0. ���������� ������.\n������� ����������� �����: ");
    scanf("%d", &num);
    while ((c = getchar()) != '\n' && c != EOF);
    while (num != 0) {
        if (num == 1) {
            cities_func(Cities, numCities, numVillages);
        }
        
        if (num == 2) {
            regions_func(Cities, Regions, numCities, numVillages);
        }
        
        if (num == 3) {
            countries_func(Cities, Countries, numCities, numVillages, numCountries);
        }
        if (num == 4) {
            continents_func(Countries, Continents, numCities, numVillages, numCountries, numContinents);
        }
        printf("����������, �������� �����, � ������� �� �� ������ ������ ����������: ");
        while ((c = getchar()) != '\n' && c != EOF);
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}