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

std::ifstream& operator>>(std::ifstream& in, City& city)
{
    string temp;
    char* buffer;
    getline(in, temp);
    if (strcmp(const_cast<char*> (temp.c_str()), "") == 0) {
        getline(in, temp);
    }
    buffer = strtok(const_cast<char*> (temp.c_str()), ";");
    city.name = buffer;
    buffer = strtok(NULL, ";");
    city.coor1 = buffer;
    buffer = strtok(NULL, ";");
    city.coor2 = buffer;
    buffer = strtok(NULL, ";");
    city.population = atoi(buffer);
    return in;
}

std::ostream& operator<<(std::ostream& out, const City& city)
{
    out << "Координаты: " << city.coor1 << ", " << city.coor2 << endl;
    out << "Население: " << city.population << " человек." << endl;
    return out;
}


void cities_func(Library* Lib) {
    string name;
    int flag = -1;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    printf("Пожалуйста, введите название города/деревни: ");
    getline(cin, name);

    for (int a = 0; a < Lib->get_ncontinents(); a++) {
         Continent& continent = Lib->get_continents(a);
        for (int b = 0; b < continent.get_ncountries(); b++) {
            Country& country = continent.get_country(b);
            for (int c = 0; c < country.get_nregions(); c++) {
                 Region& region = country.get_region(c);
                for (int d = 0; d < region.get_ncities(); d++) {
                     City& city = region.get_city(d);
                    if (name == city.get_name()) {
                        flag = d;
                        cout << city;
                        break;
                    }
                }
            }
        }
    }

    if (flag == -1) {
        printf("Название города было введено некорректно или город отсутствует в базе данных.");
        abort();
    }
}