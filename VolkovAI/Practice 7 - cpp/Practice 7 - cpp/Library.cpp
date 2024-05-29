#include "Library.h"

Library::Library() {
	this->ncontinents = 0;
	this->continents = nullptr;
}

Library::Library(int ncontinents) {
	this->ncontinents = ncontinents;
	this->continents = new Continent[ncontinents];
}

Library::Library(const Library& lib) {
	this->ncontinents = lib.ncontinents;
	this->continents = new Continent[this->ncontinents];
	for (int i = 0; i < this->ncontinents; i++) {
		this->continents[i] = lib.continents[i];
	}
}

const Library& Library::operator= (const Library& lib) {
	if (this == &lib) {
		return *this;
	}
	if (this->ncontinents != lib.ncontinents) {
		delete[] this->continents;
	}
	this->ncontinents = lib.ncontinents;
	this->continents = new Continent [this->ncontinents];
	for (int i = 0; i < this->ncontinents; i++) {
		this->continents[i] = lib.continents[i];
	}
	return *this;
}

Library::~Library() {
	delete[] this->continents;
}
