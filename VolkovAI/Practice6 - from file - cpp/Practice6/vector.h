#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

struct TVector
{
    int n;
    double* x;
    TVector();
    TVector(int n);
    TVector(FILE* f);
    /// ~TVector();

    TVector operator + (const TVector&);
    TVector operator - (const TVector&);
    TVector operator * (const TVector&);
    TVector operator = (const TVector&);
};

void alloc(TVector* v, int n);
void write(const char* outfilename, TVector* s, TVector* m, double dotproduct);
TVector sum(TVector* v1, TVector* v2);
TVector minus_v(TVector* v1, TVector* v2);
double dotproduct(TVector* v1, TVector* v2);
#endif