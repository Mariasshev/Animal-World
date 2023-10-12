#include "AnimalWorld.h"
#include "Herbivore.h"
#include "Continent.h"
#include "Carnivore.h"

#include <iostream>
using namespace std;

//counter
int AnimalWorld::count_herbivore = 0;
int AnimalWorld::count_carnivore = 0;


AnimalWorld::AnimalWorld() {
	carnivore = new Carnivore * [size];
	herbivore = new Herbivore * [size];
}
void AnimalWorld::AddCarnivore(Carnivore* carn) {
	if (count_carnivore < size) {
		carnivore[count_carnivore++] = carn;
	}
	else {
		cout << "Error" << endl;
	}

}
void AnimalWorld::AddHerbivore(Herbivore* herb) {
	if (count_herbivore < size) {
		herbivore[count_herbivore++] = herb;
	}
	else {
		cout << "Error" << endl;
	}
}
void AnimalWorld::MealsHerbivores()
{
	for (int i = 0; i < count_herbivore; i++)
	{
		herbivore[i]->EatGrass();
	}
}
void AnimalWorld::NutritionCarnivores()
{
	if (count_carnivore < count_herbivore) {
		for (int i = 0; i < count_carnivore; i++)
		{
			if (herbivore[i]->GetLife())
			{
				carnivore[i]->Eat(herbivore[i]);
			}
		}
	}
	else {
		for (int i = 0; i < count_herbivore; i++)
		{
			if (herbivore[i]->GetLife())
			{
				carnivore[i]->Eat(herbivore[i]);
			}
		}
	}
}
AnimalWorld::~AnimalWorld() {
	delete carnivore;
	delete herbivore;
}
