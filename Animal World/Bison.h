#pragma once
#include "Herbivore.h"
#include "Continent.h"
#include "AnimalWorld.h"

class Bison : public Herbivore
{
private:
	Continent* continent;
public:
	Bison();
	Bison(AnimalWorld* animal, Continent* cont, char* n, double w, bool life);
	void Print();
	char* GetContinent();
	~Bison();
};
