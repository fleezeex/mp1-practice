#include "City.h"

void cities_func(City* Cities, int numCities, int numVillages) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    printf("����������, ������� �������� ������/�������: ");
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCities + numVillages; i++) {
        if (strcmp(Cities[i].name, name) == 0) {
            printf("����������: %s %s\n", Cities[i].coor1, Cities[i].coor2);
            printf("���������: %d �������\n", Cities[i].population);
        }
    }
}