#include "City.h"

void cities_func(City* Cities, int numCities) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    printf("����������, ������� �������� ������/�������: ");
    int flag = -1;
    scanf("%[^\t\n]", &name);
    for (int i = 0; i < numCities; i++) {
        if (strcmp(Cities[i].name, name) == 0) {
            flag = i;
            printf("����������: %s %s\n", Cities[i].coor1, Cities[i].coor2);
            printf("���������: %d �������.\n", Cities[i].population);
        }
    }
    if (flag == -1) {
        printf("�������� ������ ���� ������� ����������� ��� ����� ����������� � ���� ������.");
        abort();
    }
}