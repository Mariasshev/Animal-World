#include "AnimalWorld.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Continent information: " << endl;
	AnimalWorld animalWorld;

	Continent* afrika = new Afrika("Afrika", 28, 32.00);
	afrika->Print();
	cout << endl << endl;

	Continent* northAmerika = new NorthAmerika("North Amerika", 16, 17.00);
	northAmerika->Print();
	cout << "------------------" << endl;

	Herbivore* herbivore1 = new Wildbeest(&animalWorld, afrika, "Wildbeest", 30, true);
	herbivore1->Print();
	cout << endl << endl;

	Herbivore* herbivore2 = new Bison(&animalWorld, northAmerika, "Bison", 150,true);
	herbivore2->Print();
	cout << "------------------" << endl;

	Carnivore* carnivore1 = new Wolf(&animalWorld, northAmerika, 75, "Wolf");
	carnivore1->Print();
	cout << endl << endl;

	Carnivore* carnivore2 = new Lion(&animalWorld, afrika, 100, "Lion");
	carnivore2->Print();
	cout << endl << endl;


	animalWorld.MealsHerbivores();
	herbivore1->Print();
	cout << endl << endl;
	herbivore2->Print();
	cout << "------------------" << endl;



	animalWorld.NutritionCarnivores();
	herbivore1->Print();
	cout << endl << endl;
	herbivore2->Print();
	cout << endl << endl;

	carnivore1->Print();
	cout << endl << endl;
	carnivore2->Print();
	cout << endl << endl;
}