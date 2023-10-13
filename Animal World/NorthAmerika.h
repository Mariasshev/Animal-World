#pragma once
#include "Herbivore.h"
#include "Continent.h"
#include "Carnivore.h"
#include "Continent.h"

class NorthAmerika : public Continent
{
private:
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	NorthAmerika() = default;
	NorthAmerika(const char* n, int t, double s) :Continent(n, t, s) {}
	virtual void Print();
	char* GetContinent();
	~NorthAmerika();
};
