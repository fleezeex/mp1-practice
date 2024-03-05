#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void read(const char* infilename, TVector* v1, TVector* v2) {
    int i = 0;
    FILE* f = fopen(infilename, "r");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    v1->x = (double*)malloc(v1->n * sizeof(double));
    for (i; i < v1->n; i++) {
        fscanf(f, "%lf", &(v1->x[i]));
    }
    v2->x = (double*)malloc(v1->n * sizeof(double));
    for (i = 0; i < v2->n; i++) {
        fscanf(f, "%lf", &(v2->x[i]));
    }
    fclose(f);
}

void write(const char* outfilename, TVector* v1, TVector* v2, TVector* s, TVector* m, double d) {
    double scalar;
    int i = 0;
    FILE* f = fopen(outfilename, "w+");
    if (f == NULL) {
        printf("File not found.");
        abort();
    }
    fprintf(f, "Vector addition: ");
    for (i = 0; i < s->n; i++) {
        fprintf(f, "%.2lf", s->x[i]);
        fprintf(f, "\n");
    }
    fprintf(f, "Vector substraction: ");
    for (i = 0; i < s->n; i++) {
        fprintf(f, "%.2lf", m->x[i]);
        fprintf(f, "\n");
    }
    fprintf(f, "Vector dotproduct: %lf", d);
    fclose(f);
}

void alloc(TVector* v, int n) {
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
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