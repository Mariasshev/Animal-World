#pragma once
#include "Continent.h"
#include "Herbivore.h"
#include "Carnivore.h"

class Afrika : public Continent
{
private:
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	Afrika() = default;
	Afrika(const char* n, int t, double s);
	void Print();
	~Afrika();
};

