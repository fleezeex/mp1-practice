#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 10
#define N_SYMBOLS 4

char* barcodes[N] = { "1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009", "1010" };
char* names[N] = { "NVIDIA GeForce RTX 4090 24Gb", "Intel Core i9-139000", "GIGABYTE Z790 AORUS XTREME X", "Kingston FURY Renegade 2x32GB DDR5", "be quiet! DARK POWER PRO 12 1500W", "Cooler Master Cosmos C700M", "WD Red SN700 4TB", "Cooler Master MasterAir MA612", "Samsung Odyssey Ark G97NC", "Microsoft Windows 11 Pro" };
int prices[N] = { 237990, 75990, 129990, 35990, 53490, 85490, 54990, 15490, 239990, 20990 };
int discount[N] = { 5, 20, 10, 15, 5, 10, 7, 8, 10, 50 };
int amount[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


int scanbarcode();
float output(int num, int i);
void add_amount(int i);
void final_amount();
int program();


int main() {
    int num, i;
    num = program();
    while (1) {
        if (num == 1) {
            i = scanbarcode();
            num = program();
        }
        else if (num == 2) {
            output(i, num);
            num = program();
        }
        else if (num == 3) {
            add_amount(i);
            num = program();
        }
        else if (num == 4) {
            final_amount();
            return 0;
        }
    }
}

int program() {
    setlocale(LC_ALL, "Rus");
    int num;
    printf("-------------------------\n");
    printf("1. Сканировать штрих-код; \n2. Вывод описания отсканированного наименования; \n3. Добавить данные о товаре в чек; \n4. Сформировать итоговый чек; \n");
    printf("-------------------------\n");
    scanf("%d", &num);
    return num;
}

int scanbarcode() {
    char* code[N_SYMBOLS];
    int counter = 0, i = 0;
    printf("Введите штрих-код: ");
    scanf("%s", &code);
    for (i = 0; i < N; i++) {
        if (strcmp(code, barcodes[i]) == 0) {
            printf("Товар успешно отсканирован!");
            return i;
        }
    }
    printf("Штрих-код не был найден.\n");
}

float output(int i, int num) {
    int num1 = i;
    int num0 = num;
    float endprice = 0;
    endprice = prices[num1] - (prices[num1] * discount[num1] * 0.01);
    if (num0 == 2) {
        printf("Товар: %s | Стоимость: %d руб. | Скидка: %d%% | Цена со скидкой: %f руб.\n", names[num1], prices[num1], discount[num1], endprice);
    }
    else {
        endprice = prices[num1] * amount[num1] - (prices[num1] * amount[num1] * discount[num1] * 0.01);
        printf("Товар: %s | Кол-во: %d | Стоимость: %d руб. | Скидка: %d%% | Цена со скидкой: %f руб.\n", names[num1], amount[num1], prices[num1] * amount[num1], discount[num1], endprice);
        return endprice;
    }
    return 0;
}

void add_amount(int i) {
    if (i > 0 && i < 11) {
        int num = 0;
        amount[i]++;
        printf("Товар успешно добавлен в чек!\n");
    }
    else {
        printf("Нельзя добавить товар, так как штрихкод не был отсканирован.\n");
    }
}

void final_amount() {
    int i = 0, num = 4;
    float endprice = 0;
    printf("\n-------- КАССОВЫЙ ЧЕК --------\n");
    for (i = 0; i < N; i++) {
        if (amount[i] > 0) {
            endprice += output(i, num);
        }
    }
    printf("Итого к оплате: %f руб.\n", endprice);
    printf("-----------------------------");
}