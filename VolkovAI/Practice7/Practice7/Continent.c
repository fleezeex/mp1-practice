#include "Continent.h"

void continents_func(Country* Countries, Continent* Continents, int numContinents) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int temp = 0;
    int population = 0;
    int flag = -1;
    printf("����������, ������� �������� ����������: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numContinents; i++) {
        if (strcmp(Continents[i].name, name) == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        printf("������������ ���� �������� ����������. ��������, �� ����������� � ���� ������.");
        abort();
    }
    temp = Continents[flag].ncountries;
    printf("������, �������� � ������ ������: ");
    for (int a = 0; a < Continents[flag].ncountries; a++) {
        if (temp == 1) {
            printf("%s. \n", Continents[flag].countries[a].name);
        }
        else {
            printf("%s, ", Continents[flag].countries[a].name);
        }
        temp--;
        population += Continents[flag].countries[a].population;
    }
    printf("����������� ��������� �� ����������: %d �������. \n", population);
}