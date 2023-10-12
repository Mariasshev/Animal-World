#include "Wolf.h"
#include "Carnivore.h"
#include "Continent.h"
#include "AnimalWorld.h"
#include <iostream>
using namespace std;

Wolf::Wolf() {
		power = 0;
		continent = nullptr;
	}
Wolf::Wolf(AnimalWorld* animal, Continent* cont, char* n, int p) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		animal->AddCarnivore(this);
		continent = cont;
		power = p;
	}
	void Wolf::Print() {
		cout << "Name: " << name << endl;
		cout << "Weight: " << power << endl;
		cout << "Continent: " << GetContinent();
	}
	void Wolf::EatHerbivore(Herbivore* obj) {
		if (continent->GetContinent() != obj->GetContinent()) {
			cout << "These animals are from different continents!!" << endl;
		}
		else {
			cout << "-1 " << obj->GetNameH() << endl;
			cout << "Wolf power: " << power << endl;
			cout << "Wolf weight: " << obj->GetWeight() << endl;
			if (obj->GetWeight() < power)
			{
				power += 10;
			}
			else
			{
				power -= 10;
			}
			obj->SetLife(false);
		}
	}
	Wolf::~Wolf() {
		delete continent;
	}


