#include "Library.h"

void continents_func(Library* Lib) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int a = 0;
    int b = 0;
    int temp = 0;
    int population = 0;
    int flag = -1;
    printf("����������, ������� �������� ����������: ");
    scanf("%[^\t\n]", &name);

    for (a = 0; a < Lib->ncontinents; a++) {
        if (strcmp(Lib->continents[a].name, name) == 0) {
            flag = b;
            temp = Lib->continents[a].ncountries;
            printf("������, ������������� �� ��������: ");
            for (b = 0; b < Lib->continents[a].ncountries; b++) {
                if (temp == 1) {
                    printf("%s. \n", Lib->continents[a].countries[b].name);
                }
                else {
                    printf("%s, ", Lib->continents[a].countries[b].name);
                }
                temp--;
                population += Lib->continents[a].countries[b].population;
            }
            printf("����������� ��������� �� ����������: %d �������. \n", population);
        }
    }

    if (flag == -1) {
        printf("������������ ���� �������� ����������. ��������, �� ����������� � ���� ������.");
        abort();
    }
}