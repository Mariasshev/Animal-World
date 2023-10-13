#include "Afrika.h"
#include "Continent.h"
#include <iostream>
using namespace std;

Afrika::Afrika() = default;

Afrika::Afrika(const char* n, int t, double s) :Continent(n, t, s) {}

void Afrika::Print() {
	cout << "Continent: " << name << endl;
	cout << "Square: " << square << endl;
	cout << "temperature: " << temperature << endl;
}

Afrika::~Afrika() {
	delete herbivore;
	delete carnivore;
}

