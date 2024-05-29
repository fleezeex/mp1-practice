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

const Continent& Continent::operator= (const Continent& continent) {
	if (this == &continent) {
		return *this;
	}
	if (this->ncountries != continent.ncountries) {
		delete[] this->countries;
	}
    this->name = continent.name;
    this->ncountries = continent.ncountries;
	this->countries = new Country[this->ncountries];
	for (int i = 0; i < this->ncountries; i++) {
		this->countries[i] = continent.countries[i];
	}
	return *this;
}

Continent::~Continent() {
    delete[] this->countries;
}

std::ifstream& operator>>(std::ifstream& in, Continent& continent)
{
    string temp;
    char* buffer;
    getline(in, temp);
    if (strcmp(const_cast<char*> (temp.c_str()), "") == 0) {
        getline(in, temp);
    }

    buffer = strtok(const_cast<char*> (temp.c_str()), ";");
    continent.name = buffer;
    buffer = strtok(NULL, ";");
    continent.ncountries = atoi(buffer);
    continent.countries = new Country[continent.ncountries];
    return in;
}

std::ostream& operator<< (std::ostream& out, Continent& continent) {
    int temp = continent.ncountries;
    int population = 0;
    printf("Страны, входящие в состав континента: ");
    for (int a = 0; a < continent.ncountries; a++) {
        if (temp == 1) {
            cout << continent.countries[a].get_name() << ". \n";
        }
        else {
            cout << continent.countries[a].get_name() << ", ";
        }
        temp--;
        population += continent.countries[a].get_population();
    }
    cout << "Численность населения на континенте: " << population << " человек. \n";
    return out;
}

void continents_func(Library* Lib) {
    string name;
    int flag = -1;
    int a = 0;
    int b = 0;
    int c = 0;
    cout << "Пожалуйста, введите название континента: ";
    getline(cin, name);

    for (int a = 0; a < Lib->get_ncontinents(); a++) {
        Continent& continent = Lib->get_continents(a);
        if (name == continent.get_name()) {
            flag = b;
            cout << continent;
            break;
        }
    }

    if (flag == -1) {
        cout << "Название континента было введено некорректно или континент отсутствует в базе данных.";
        abort();
    }
}