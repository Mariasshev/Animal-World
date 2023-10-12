#pragma once
#include "Herbivore.h"
#include "Carnivore.h"

class Afrika : public Continent
{
private:
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	Afrika() = default;
	Afrika(const char* n, int t, double s) :Continent(n, t, s) {}
	virtual void Print();
	char* GetContinent();
	~Afrika();
};

