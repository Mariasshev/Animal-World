#include "Continent.h"
#include <iostream>
using namespace std;

Continent::Continent() {
	name = nullptr;
	temperature = 0;
	square = 0;
}
Continent::Continent(const char* n, int t, double s) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	temperature = t;
	square = s;
}
void Continent::Input() {
	cout << "Enter continent name: ";
	char buff[15];
	cin >> buff;
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
	cout << "Enter temperature: ";
	cin >> temperature;
	cout << "Enter square: ";
	cin >> square;
}
void Continent::Print() {
	cout << "Continent: " << name << endl;
	cout << "Square: " << square << endl;
	cout << "temperature: " << temperature << endl;
}
char* Continent::GetContinent() {
	return name;
}
Continent::~Continent() {
	delete name;
}
