#include "Library.h"
Continent::Continent() {
    this->ncountries = 0;
    this->countries = nullptr;
    this->name = "";
}

Continent::Continent(string name, int ncountries) {
    this->name = name;
    this->ncountries = ncountries;
    this->countries = new Country[ncountries];
}

Continent::Continent(const Continent& continent) {
    this->name = continent.name;
    this->ncountries = continent.ncountries;
    this->countries = new Country[this->ncountries];
    for (int i = 0; i < this->ncountries; i++) {
        this->countries[i] = continent.countries[i];
    }
}

Continent::~Continent() {
    delete[] this->countries;
}
