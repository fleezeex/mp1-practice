#include "Library.h"

void menu(Library* Lib) {
    int c;
    int num = 1000;
    printf("���������� ��������.\n");
    printf("����������, �������� �����, � ������� �� �� ������ ������ ����������. \n1. ������/�������.\n2. �������.\n3. ������.\n4. ��������.\n0. ���������� ������.\n������� ����������� �����: ");
    cin >> num;
    while ((c = getchar()) != '\n' && c != EOF);
    while (num != 0) {
        if (num == 1) {
            cities_func(Lib);
        }
        if (num == 2) {
            regions_func(Lib);
        }

        if (num == 3) {
           countries_func(Lib);
        }
        if (num == 4) {
           continents_func(Lib);
        }
        printf("����������, �������� �����, � ������� �� �� ������ ������ ����������: ");
        cin >> num;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}