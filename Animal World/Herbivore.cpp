#include "Herbivore.h"
#include <iostream>
using namespace std;

Herbivore::Herbivore() 
{
		weight = 0;
		isLife = false;
		name = nullptr;
}
Herbivore::Herbivore(double w, bool life, char* n) 
{
		weight = w;
		isLife = life;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
}
void Herbivore::EatGrass() 
{
	weight += 10;
}

void Herbivore::Input() 
{
	cout << "Enter animal: ";
	char buff[15];
	cin >> buff;
	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);
	cout << "Enter weight: ";
	cin >> weight;
	cout << "Is this animal alive? ";
	cin >> isLife;
}
char* Herbivore::GetNameH() 
{
	return name;
}
double Herbivore::GetWeight() 
{
	return weight;
}
bool Herbivore::GetLife() 
{
	return isLife;
}

void Herbivore::SetNameH(char* n) 
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
void Herbivore::SetWeight(double w) 
{
	weight = w;
}
void Herbivore::SetLife(bool l) 
{
	isLife = l;
}

