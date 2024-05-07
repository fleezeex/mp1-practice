#include "Library.h"

Region::Region() {
	this->name = "";
	this->cities = nullptr;
	this->ncities = 0;
	this->capital.name = "";
	this->population = 0;
}
Region::Region(string name, int population, string capitalname, int ncities) {
	this->name = name;
	this->population = population;
	this->capital.name = capitalname;
	this->ncities = ncities;
	this->cities = new City[ncities];
}
Region::Region(const Region& region) {
	this->name = region.name;
	this->population = region.population;
	this->capital.name = region.capital.name;
	this->ncities = region.ncities;
	this->cities = new City[ncities];
	for (int i = 0; i < region.ncities; i++) {
		this->cities[i] = region.cities[i];
	}
}

Region::~Region() {
	delete[] this->cities;
}