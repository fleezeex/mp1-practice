#include "vector.h"
#include <cstdlib>
#include <iostream>
using namespace std;

TVector::TVector() {
    this->n = 0;
    this->x = nullptr;
}

TVector::TVector(int n) {
    this->n = n;
    this->x = new double [n];
}

TVector::TVector(FILE* f) {
    int i = 0;
    fscanf(f, "%d", &(this->n));
    this->x = new double[this->n];
    for (i; i < this->n; i++) {
        fscanf(f, "%lf", &(this->x[i]));
    }
}
/*
TVector::~TVector() {
    delete[] this->x;
}
*/
TVector TVector::operator+ (const TVector& v) {
    int i = 0;
    if (this->n != v.n) {
        throw std::exception("Different length.");
    }
    TVector res(this->n);
    for (i; i < this->n; i++) {
        res.x[i] = this->x[i] + v.x[i];
    }
    return res;
}

TVector TVector::operator- (const TVector& v) {
    int i = 0;
    if (this->n != v.n) {
        throw std::exception("Different length.");
    }
    TVector res(this->n);
    for (i; i < this->n; i++) {
        res.x[i] = this->x[i] - v.x[i];
    }
    return res;
}

TVector TVector::operator= (const TVector& v) {
    int i = 0;
    if (this->n != v.n) {
        throw std::exception("Different length.");
    }
    TVector res(this->n);
    for (i; i < this->n; i++) {
        res.x[i] = v.x[i];
    }
    return res;
}

void write(const char* outfilename, TVector* s, TVector* m, double d) {
    int i = 0;
    FILE* f = fopen(outfilename, "w+");
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
        cout << "v1->n != v2->n";
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

TVector minus_v(TVector* v1, TVector* v2) {
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