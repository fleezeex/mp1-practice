#include "vector.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

TVector::TVector() {
    this->n = 0;
    this->x = nullptr;
}

TVector::TVector(int n) {
    this->n = n;
    this->x = new double [n];
}


TVector::~TVector() {
    delete[] this->x;
}

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

double TVector::operator* (const TVector& v) {
    double scalar = 0.0;
    int i = 0;
    if (this->n != v.n) {
        throw std::exception("Different length.");
    }
    for (; i < this->n; i++) {
        scalar += this->x[i] * v.x[i];
    }
    return scalar;
}

std::istream& operator>>(std::istream& in, TVector& v)
{
    std::cout << "Input n: ";
    in >> v.n;
    std::cout << "Input x: ";
    if (v.x != nullptr)
    {
        delete[] v.x;
    }
    v.x = new double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        in >> v.x[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const TVector& v)
{
    out << "Vector: ";
    for (int i = 0; i < v.n; i++)
    {
        out << v.x[i] << " ";
    }
    return out;
}
