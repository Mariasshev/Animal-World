#pragma once
#include <iostream>
using namespace std;

class AnimalWorld
{
private:
	int size = 4;
	Carnivore** carnivore;
	Herbivore** herbivore;
public:
	static int count_herbivore;
	static int count_carnivore;
	AnimalWorld();
	void AddCarnivore(Carnivore* carn);
	void AddHerbivore(Herbivore* herb);
	void MealsHerbivores();
	void NutritionCarnivores();
	~AnimalWorld();
};

