#include "Carnivore.h"
#include <iostream>
using namespace std;

Carnivore::Carnivore() 
{
		power = 0;
		name = nullptr;
}
Carnivore::Carnivore(int p, char* n) 
{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		power = p;
}

void Carnivore::Input() 
{
	cout << "Enter animal: ";
	char buff[15];
	cin >> buff;
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
	cout << "Enter power: ";
	cin >> power;
}

char* Carnivore::GetNameC() 
{
	return name;
}

int Carnivore::GetPower() {
	return power;
}

void Carnivore::SetNameC(char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
void Carnivore::SetPower(double p) {
	power = p;
}

