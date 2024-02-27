#include "vector.h"
#include <stdlib.h>

void alloc(TVector* v, int n) {
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* v) {
    int i = 0;
    printf("Input the coordinates of the vector: \n");
    for (i; i < v->n; i++) {
        scanf("%lf", &(v->x[i]));
    }
}

void print(TVector* v) {
    int i = 0;
    printf("Vector: ");
    for (i; i < v->n; i++) {
        printf("%lf", v->x[i]);
        printf("\n");
    }
}

TVector sum(TVector* v1, TVector* v2) {
    TVector res;
    int i = 0;
    if (v1->n != v2->n) {
        printf(v1->n != v2->n);
        res.x = NULL;
        res.n = 0;
        return res;
    }
    alloc(&res, v1->n);
    for (; i < res.n; i++) {
        res.x[i] = v1->x[i] + v2->x[i];
    }
    return res;
}

TVector minus(TVector* v1, TVector* v2) {
    TVector res;
    int i = 0;
    if (v1->n != v2->n) {
        res.x = NULL;
        res.n = 0;
        return res;
    }
    alloc(&res, v1->n);
    for (; i < res.n; i++) {
        res.x[i] = v1->x[i] - v2->x[i];
    }
    return res;
}


double dotproduct(TVector* v1, TVector* v2) {
    double scalar = 0.0;
    int i = 0;
    if (v1->n != v2->n) {
        return 0;
    }
    for (; i < v1->n; i++) {
        scalar += v1->x[i] * v2->x[i];
    }
    return scalar;
}