#pragma once
#include <iostream>
using namespace std;

class Lion : public Carnivore
{
private:
	Continent* continent;
public:
	Lion();
	Lion(AnimalWorld* animal, Continent* cont, char* n, int p);
	void Print();
	virtual void EatHerbivore(Herbivore* obj);
	~Lion();
};

