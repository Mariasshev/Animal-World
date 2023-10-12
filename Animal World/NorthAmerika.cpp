#include "NorthAmerika.h"
#include <iostream>
using namespace std;

void NorthAmerika:: Print() {
	cout << "Continent: " << name << endl;
	cout << "Square: " << square << endl;
	cout << "temperature: " << temperature << endl;
}
char* NorthAmerika::GetContinent() {
	return name;
}
NorthAmerika::~NorthAmerika() {
	delete herbivore;
	delete carnivore;
}

