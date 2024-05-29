#include "Library.h"

Country::Country() {
	this->name = "";
	this->square = 0;
	this->population = 0;
	this->form = GovermentForm::Republic;
	this->capital.set_name("");
	this->nregions = 0;
	this->regions = nullptr;
}

Country::Country(string name, GovermentForm form, string capitalname, int population, float square, int nregions) {
	this->name = name;
	this->form = form;
	this->capital.set_name(capitalname);
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

const Country& Country::operator= (const Country& country) {
	if (this == &country) {
		return *this;
	}
	if (this->nregions != country.nregions) {
		delete[] this->regions;
	}
	this->capital = country.capital;
	this->form = country.form;
	this->name = country.name;
	this->nregions = country.nregions;
	this->population = country.population;
	this->square = country.square;
	this->regions = new Region[this->nregions];
	for (int i = 0; i < this->nregions; i++) {
		this->regions[i] = country.regions[i];
	}
	return *this;
}

Country::~Country() {
	delete[] this->regions;
}

std::ifstream& operator>>(std::ifstream& in, Country& country) {
	string temp;
	char* buffer;
	getline(in, temp);
	if (strcmp(const_cast<char*> (temp.c_str()), "") == 0) {
		getline(in, temp);
	}

	buffer = strtok(const_cast<char*> (temp.c_str()), ";");
	country.name = buffer;
	buffer = strtok(NULL, ";");
	if (buffer == "республика")
		country.form = GovermentForm::Republic;
	else if (buffer == "монархия")
		country.form = GovermentForm::Monarchy;
	buffer = strtok(NULL, ";");
	country.capital.set_name(buffer);
	buffer = strtok(NULL, ";");
	country.square = atof(buffer);
	buffer = strtok(NULL, ";");
	country.population = atof(buffer);
	buffer = strtok(NULL, ";");
	country.nregions = atoi(buffer);
	country.regions = new Region[country.nregions];
	return in;
}

std::ostream& operator<< (std::ostream& out, Country& country) {
	int temp = country.nregions;
	int cities_population = 0;
	cout << "Регионы, входящие в состав страны: ";
	for (int a = 0; a < country.nregions; a++) {
		if (temp == 1) {
			cout << country.regions[a].get_name() << ". \n";
		}
		else {
			cout << country.regions[a].get_name() << ", ";
		}
		temp--;
		for (int b = 0; b < country.regions[a].get_ncities(); b++) {
			cities_population +=country.regions[a].get_city(b).get_population();
		}
	}
	if (country.form == 0) {
		cout << "Форма правления - монархия." << endl;
	}
	if (country.form == 1) {
		cout << "Форма правления - республика." << endl;
	}
	cout << "Столица страны: " << country.capital.get_name() << ". \n";
	cout.precision(2);
	cout << "Площадь страны: " << fixed << country.square << " квадратных километров. \n";
	cout << "Численность населения: " << country.population << " человек. \n";
	cout << "Процент городского населения: " << 100 - (double)cities_population / ((double)country.population) << "%.\n";
	return cout;
}

void countries_func(Library* Lib) {
	string name;
	int flag = -1;
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "Пожалуйста, введите название страны: ";
	getline(cin, name);

	for (int a = 0; a < Lib->get_ncontinents(); a++) {
		Continent& continent = Lib->get_continents(a);
		for (int b = 0; b < continent.get_ncountries(); b++) {
			Country& country = continent.get_country(b);
			if (name == country.get_name()) {
				flag = b;
				cout << country;
				break;
			}
		}
	}

	if (flag == -1) {
		cout << "Название страны было введено некорректно или страна отсутствует в базе данных.";
		abort();
	}
}