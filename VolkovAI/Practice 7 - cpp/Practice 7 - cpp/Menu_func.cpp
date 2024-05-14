#include "Library.h"

void menu(Library* Lib) {
    int c;
    int num = 1000;
    printf("Справочник географа.\n");
    printf("Пожалуйста, выберите пункт, о котором бы Вы хотели узнать информацию. \n1. Города/деревни.\n2. Регионы.\n3. Страны.\n4. Материки.\n0. Завершение работы.\nВведите необходимый пункт: ");
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
        printf("Пожалуйста, выберите пункт, о котором бы Вы хотели узнать информацию: ");
        cin >> num;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}