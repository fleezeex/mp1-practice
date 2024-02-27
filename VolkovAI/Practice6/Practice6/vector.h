#ifndef VECTOR_H
#define VECTOR_H


typedef struct 
{
    int n;
    double* x;
} TVector;

void alloc(TVector* v, int n);
void fill(TVector* v);
void print(TVector* v);
TVector sum(TVector* v1, TVector* v2);
TVector minus(TVector* v1, TVector* v2);
double dotproduct(TVector* v1, TVector* v2);
#endif