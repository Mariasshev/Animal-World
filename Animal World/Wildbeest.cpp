#include "Wildbeest.h"
#include "Herbivore.h"
#include "Continent.h"
#include "AnimalWorld.h"
#include <iostream>
using namespace std;

Wildbeest:: Wildbeest() 
{
		weight = 0;
		isLife = false;
}
Wildbeest::Wildbeest(AnimalWorld* animal, Continent* cont, char* n, double w, bool life) 
{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		animal->AddHerbivore(this);
		continent = cont;
		weight = w;
		isLife = life;
}
void Wildbeest::Print() 
{
	cout << "Name: " << name << endl;
	cout << "Weight: " << weight << endl;
	cout << "Continent: " << GetContinent();
	cout << "Is alive? " << isLife << endl;
}
char* Wildbeest::GetContinent()
{
	return continent->GetContinent();
}
Wildbeest::~Wildbeest() 
{
	delete continent;
}
