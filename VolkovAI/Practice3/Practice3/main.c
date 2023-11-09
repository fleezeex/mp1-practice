#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int cowsbulls (int *num, int *user_num, int n);
void fill_rand (int *num, int n);
void fill_user (int *user_num, int n);

int main () {
    int n = 0, num[] = {0, 0, 0, 0, 0}, user_num[] = {0, 0, 0, 0, 0}, bulls, att = 0;
    do {
        printf ("Input the length of the number: ");
        scanf ("%d", &n);
    } while ((n<2) || (n>5));
    srand ((unsigned int) time (0));
    fill_rand (&(num[0]), n);
    do {
        fill_user (&(user_num[0]), n);
        bulls = cowsbulls (&(num[0]), &(user_num[0]), n);
        att++;
    } while (bulls != n);
    printf ("\nYou've won! Number of attempts: %d", att);
    return 0;
}

int cowsbulls (int *num, int *user_num, int n) {
    int i = 0, j = 0, cows = 0, bulls = 0;
    for (i = 0; i<n; i++) {
                for (j = 0; j<n; j++) {
                    if (num [i] == user_num [j]) {
                        if (i == j) {
                            bulls += 1;
                        }
                        else {
                            cows += 1;
                        }
                    }
                }
    }
    printf ("Cows = %d, bulls = %d.", cows, bulls);
    return bulls;
}

void fill_rand (int *num, int n) {
    int i = 0, j = 0, number = 0, flag = 0;
    num[0] = 1 + rand () % 9;
    for (i = 1; i < n; i++) {
        do {
            number = rand() % 10;
            flag = 0;
            for (j = 0; j < i; j++) {
                if (num[j] == number) {
                    flag = 1;
                    break;
                }
            }
        } while (flag);
        num[i] = number;
    }
}

void fill_user (int *user_num, int n) {
    int current = 0;
    printf ("\nInput your number: ");
    scanf ("%d", &current);
    user_num[0] = current / pow (10, n-1);
    user_num[n-1] = current % 10;
    if (current > 100) {
        user_num[1] = (int) (current / pow (10, n-2)) % 10;
        if (current > 1000) {
            user_num[2] = (int) (current / pow (10, n-3)) % 10;
            if (current > 10000) {
                user_num[3] = (current / 10) % 10;
            }
        }
    }
}