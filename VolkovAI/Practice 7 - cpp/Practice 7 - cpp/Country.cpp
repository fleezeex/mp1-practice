#include "Library.h"


Country::Country() {
	this->name = "";
	this->square = 0;
	this->population = 0;
	this->form = GovermentForm::Republic;
	this->capital.name = "";
	this->nregions = 0;
	this->regions = nullptr;
}

Country::Country(string name, GovermentForm form, string capitalname, int population, float square, int nregions) {
	this->name = name;
	this->form = form;
	this->capital.name = capitalname;
	this->population = population;
	this->square = square;
	this->nregions = nregions;
	this->regions = new Region[nregions];
}

Country::Country(const Country & country) {
	this->name = country.name;
	this->form = country.form;
	this->capital = country.capital;
	this->square = country.square;
	this->population = country.population;
	this->nregions = country.nregions;
	this->regions = new Region[this->nregions];
	for (int i = 0; i < country.nregions; i++) {
		this->regions[i] = country.regions[i];
	}
}
Country::~Country() {
	delete[] this->regions;
}