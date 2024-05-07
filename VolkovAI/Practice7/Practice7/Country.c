#include "Library.h"

void countries_func(Library Lib) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[buffer_size];
    int flag = -1;
    int temp = 0;
    int cities_population = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("����������, ������� �������� ������: ");
    scanf("%[^\t\n]", &name);

    for (a = 0; a < Lib.ncontinents; a++) {
        for (b = 0; b < Lib.continents[a].ncountries; b++) {
            if (strcmp(name, Lib.continents[a].countries[b].name) == 0) {
                temp = Lib.continents[a].countries[b].nregions;
                flag = b;
                printf("�������, �������� � ������ ������: ");
                for (c = 0; c < Lib.continents[a].countries[b].nregions; c++) {
                    if (temp == 1) {
                        printf("%s. \n", Lib.continents[a].countries[b].regions[c].name);
                    }
                    else {
                        printf("%s, ", Lib.continents[a].countries[b].regions[c].name);
                    }
                    temp--;
                    for (d = 0; d < Lib.continents[a].countries[b].regions[c].ncities; d++) {
                        cities_population += Lib.continents[a].countries[b].regions[c].cities[d].population;
                    }
                }
                if (Lib.continents[a].countries[b].form == 0) {
                    printf("����� ��������� - ��������. \n");
                }
                if (Lib.continents[a].countries[b].form == 1) {
                    printf("����� ��������� - ����������. \n");
                }
                printf("������� ������: %s. \n", Lib.continents[a].countries[b].capital);
                printf("������� ������: %.2f ���������� ����������. \n", Lib.continents[a].countries[b].square);
                printf("����������� ���������: %d �������. \n", Lib.continents[a].countries[b].population);
                printf("������� ���������� ���������: %lf%%.\n", 100 - (double)cities_population / ((double)Lib.continents[a].countries[b].population));
            }
        }
    }

    if (flag == -1) {
        printf("�������� ������ ���� ������� ����������� ��� ������ ����������� � ���� ������.");
        abort();
    }
}