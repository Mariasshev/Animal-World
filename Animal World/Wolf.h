#pragma once
#include <iostream>
using namespace std;

class Wolf : public Carnivore
{
private:
	Continent* continent;
public:
	Wolf();
	Wolf(AnimalWorld* animal, Continent* cont, char* n, int p);
	void Print();
	virtual void EatHerbivore(Herbivore* obj);
	~Wolf();
};

