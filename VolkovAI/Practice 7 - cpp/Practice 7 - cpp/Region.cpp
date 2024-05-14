#include "Library.h"

Region::Region() {
	this->name = "";
	this->cities = nullptr;
	this->ncities = 0;
	this->capital.set_name("");
	this->population = 0;
}
Region::Region(string name, int population, string capitalname, int ncities) {
	this->name = name;
	this->population = population;
	this->capital.set_name(capitalname);
	this->ncities = ncities;
	this->cities = new City[ncities];
}
Region::Region(const Region& region) {
	this->name = region.name;
	this->population = region.population;
	this->capital = region.capital;
	this->ncities = region.ncities;
	this->cities = new City[ncities];
	for (int i = 0; i < region.ncities; i++) {
		this->cities[i] = region.cities[i];
	}
}

const Region& Region::operator= (const Region& region) {
	if (region.cities == this->cities) {
		return *this;
	}
	if (this->ncities != region.ncities) {
			delete[] this->cities;
	}
	this->capital = region.capital;
	this->name = region.name;
	this->ncities = region.ncities;
	this->population = region.population;
	this->cities = new City[this->ncities];
	for (int i = 0; i < this->ncities; i++) {
		this->cities[i] = region.cities[i];
	}
	return *this;
}

Region::~Region() {
	delete[] this->cities;
}

std::ifstream& operator>>(std::ifstream& in, Region& region)
{
	string temp;
	char* buffer;
	getline(in, temp);
	if (strcmp(const_cast<char*> (temp.c_str()), "") == 0) {
		getline(in, temp);
	}

	buffer = strtok(const_cast<char*> (temp.c_str()), ";");
	region.name = buffer;
	buffer = strtok(NULL, ";");
	region.population = atoi(buffer);
	buffer = strtok(NULL, ";");
	region.capital.set_name(buffer);
	buffer = strtok(NULL, ";");
	region.ncities = atoi(buffer);
	region.cities = new City[region.ncities];
	return in;
}

std::ostream& operator<< (std::ostream& out, Region& region) {
	int cities_population = 0;
	int temp = 0;
	cout << "Столица региона: " << region.capital.get_name() << endl;
	cout << "Города, входящие в состав региона: ";
	temp = region.ncities;
	for (int a = 0; a < region.ncities; a++) {
		if (temp == 1) {
			cout << region.cities[a].get_name() << ".\n" ;
		}
		else {
			cout << region.cities[a].get_name() << ", ";
		}
		cities_population += region.cities[a].get_population();
		temp--;
	}
	cout << "Численность населения: " << region.population << " человек." << endl;
	cout << "Процент городского населения: " << 100 - (double)cities_population / (double)region.population << "%." << endl;
	return cout;
}

void regions_func(Library* Lib) {
	string name;
	int flag = -1;
	int a = 0;
	int b = 0;
	int c = 0;
	printf("Пожалуйста, введите название региона: ");
	getline(cin, name);

	for (int a = 0; a < Lib->get_ncontinents(); a++) {
		Continent& continent = Lib->get_continents(a);
		for (int b = 0; b < continent.get_ncountries(); b++) {
			Country& country = continent.get_country(b);
			for (int c = 0; c < country.get_nregions(); c++) {
				Region& region = country.get_region(c);
				if (name == region.get_name()) {
					flag = c;
					cout << region;
					break;
				}
			}
		}
	}

	if (flag == -1) {
		printf("Название региона было введено некорректно или регион отсутствует в базе данных.");
		abort();
	}
}