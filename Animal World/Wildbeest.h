#pragma once
#include "Herbivore.h"
#include "Continent.h"
#include "AnimalWorld.h"

class Wildbeest : public Herbivore
{
private:
	Continent* continent;
public:
	Wildbeest();
	Wildbeest(AnimalWorld* animal, Continent* cont, char* n, double w, bool life);
	void Print();
	char* GetContinent();
	~Wildbeest();
};

