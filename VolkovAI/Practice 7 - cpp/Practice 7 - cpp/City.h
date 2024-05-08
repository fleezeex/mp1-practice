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
    string coor1;
    string coor2;
    int population;

    public:
    string name;
    City();
    City(string name, string coor1, string coor2, int population);
    City(const City& city);
    
    const City& operator = (const City&);
    friend std::ifstream& operator>>(std::ifstream& in, City& city)
    {
        string temp;
        char* buffer;
        in >> temp;
        
        buffer = strtok(const_cast<char*> (temp.c_str()), ";");
        city.name = buffer;
        buffer = strtok (NULL, ";");
        city.coor1 = buffer;
        buffer = strtok (NULL, ";");
        city.coor2 = buffer;
        buffer = strtok (NULL, ";");
        city.coor1 = atoi(buffer);
        return in;
    }
};

std::istream& operator>>(std::istream& in, City& city);
//void cities_func(Library lib);
#endif
