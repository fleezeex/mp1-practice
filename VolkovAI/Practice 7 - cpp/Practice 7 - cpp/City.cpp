#include "Library.h"

City::City() {
	this->name = "";
	this->coor1 = "";
	this->coor2 = "";
	this->population = 0;
}

City::City(string name, string coor1, string coor2, int population) {
	this->name = name;
	this->coor1 = coor1;
	this->coor2 = coor2;
	this->population = population;
}

City::City(const City& city) {
	this->name = city.name;
	this->coor1 = city.coor1;
	this->coor2 = city.coor2;
	this->population = city.population;
}

const City& City::operator= (const City& city) {
    if (this == &city)
    {
        return *this;
    }
	this->name = city.name;
	this->coor1 = city.coor1;
	this->coor2 = city.coor2;
	this->population = city.population;
    return *this;
}