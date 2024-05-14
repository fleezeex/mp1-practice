#pragma once
#ifndef CITY
#define CITY
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

class City
{
    private:
    string name;
    string coor1;
    string coor2;
    int population;

    public:
    City();
    City(string name, string coor1, string coor2, int population);
    City(const City& city);

    void set_name(string name) {
        this->name = name;
    }
    string get_name() const {
        return this->name;
    }
    int get_population() const {
        return this->population;
    }
    
    const City& operator = (const City&);

    friend std::ifstream& operator>>(std::ifstream& in, City& city);
    friend std::ostream& operator<< (std::ostream& out, const City& city);
    
};
//
#endif
