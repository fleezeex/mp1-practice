#ifndef VECTOR_H
#define VECTOR_H


typedef struct 
{
    int n;
    double* x;
} TVector;

void alloc(TVector* v, int n);
void read(const char* infilename, TVector* v1, TVector* v2);
void write(const char* outfilename, TVector* v1, TVector* v2, TVector* s, TVector* m, double dotproduct);
TVector sum(TVector* v1, TVector* v2);
TVector minus(TVector* v1, TVector* v2);
double dotproduct(TVector* v1, TVector* v2);
#endif