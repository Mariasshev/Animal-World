#include "Lion.h"
#include "Carnivore.h"
#include "Continent.h"
#include "AnimalWorld.h"
#include <iostream>
using namespace std;

Lion::Lion()
{
	power = 0;
	continent = nullptr;
}
Lion::Lion(AnimalWorld* animal, Continent* cont, char* n, int p)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	animal->AddCarnivore(this);
	continent = cont;
	power = p;
}
void Lion::Print()
{
	cout << "Name: " << name << endl;
	cout << "Weight: " << power << endl;
	cout << "Continent: " << GetContinent();
}
void Lion::EatHerbivore(Herbivore* obj)
{
	if (continent->GetContinent() != obj->GetContinent())
	{
		cout << "These animals are from different continents!!" << endl;
	}
	else 
	{
		cout << "-1 " << obj->GetNameH() << endl;
		cout << "Lion power: " << power << endl;
		cout << "Lion weight: " << obj->GetWeight() << endl;
		if (obj->GetWeight() < power)
		{
			power += 10;
		}
		else
		{
			power -= 10;
		}
		obj->SetLife(false);
	}
}
Lion::~Lion() {
	delete continent;
}
