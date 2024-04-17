#include "Country.h"

void countries_func(City* Cities, Country* Countries, int numCities, int numCountries) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int flag = -1;
    int temp = 0;
    int cities_population = 0;
    printf("����������, ������� �������� ������: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCountries; i++) {
        if (strcmp(Countries[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("�������� ������ ���� ������� ����������� ��� ������ ����������� � ���� ������.");
        abort();
    }
    temp = Countries[flag].nregions;
    for (int a = 0; a < Countries[flag].nregions; a++) {
        if (temp == Countries[flag].nregions) {
            printf("�������, �������� � ������ ������: ");
                }
                if (temp == 1) {
                    printf("%s. \n", Countries[flag].regions[a]);
                }
                else {
                    printf("%s, ", Countries[flag].regions[a]);
                }
                temp--;
                for (int b = 0; b < Countries[flag].regions[a].ncities; b++) {
                    cities_population += Countries[flag].regions[a].cities[b].population;
                }
    }
    if (Countries[flag].form == 0) {
        printf("����� ��������� - ��������. \n");
    }
    if (Countries[flag].form == 1) {
        printf("����� ��������� - ����������. \n");
    }
    printf("������� ������: %s. \n", Countries[flag].capital);
    printf("������� ������: %.2f ���������� ����������. \n", Countries[flag].square);
    printf("����������� ���������: %d �������. \n", Countries[flag].population);
    printf("������� ���������� ���������: %lf%%.\n", 100 - (double)cities_population / ((double)Countries[flag].population));
}