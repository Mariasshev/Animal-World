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
	AnimalWorld() {
		carnivore = new Carnivore * [size];
		herbivore = new Herbivore * [size];
	}
	void AddCarnivore(Carnivore* carn) {
		if (count_carnivore < size) {
			carnivore[count_carnivore++] = carn;
		}
		else {
			cout << "Error" << endl;
		}

	}
	void AddHerbivore(Herbivore* herb) {
		if (count_herbivore < size) {
			herbivore[count_herbivore++] = herb;
		}
		else {
			cout << "Error" << endl;
		}
	}
	void MealsHerbivores()
	{
		for (int i = 0; i < count_herbivore; i++)
		{
			herbivore[i]->EatGrass();
		}
	}
	void NutritionCarnivores()
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
	~AnimalWorld() {
		delete carnivore;
		delete herbivore;
	}
};

int AnimalWorld::count_herbivore = 0;
int AnimalWorld::count_carnivore = 0;


class NorthAmerika : public Continent
{
private:
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	NorthAmerika() = default;
	NorthAmerika(const char* n, int t, double s) :Continent(n, t, s) {}
	virtual void Print() {
		cout << "Continent: " << name << endl;
		cout << "Square: " << square << endl;
		cout << "temperature: " << temperature << endl;
	}
	char* GetContinent() {
		return name;
	}
	~NorthAmerika() {
		delete herbivore;
		delete carnivore;
	}
};


class Bison: public Herbivore
{
private:
	Continent* continent;
public:
	Bison() {
		weight = 0;
		isLife = false;
	}
	Bison(AnimalWorld* animal, Continent* cont, char* n, double w, bool life) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		animal->AddHerbivore(this);
		continent = cont;
		weight = w;
		isLife = life;
	}
	void Print() {
		cout << "Name: " << name << endl;
		cout << "Weight: " << weight << endl;
		cout << "Continent: " << GetContinent();
		cout << "Is alive? " << isLife << endl;
	}
	char* GetContinent()
	{
		return continent->GetContinent();
	}
	~Bison() {
		delete continent;
	}

};

class Lion: public Carnivore
{
private:
	Continent* continent;
public:
	Lion() 
	{
		power = 0;
		continent = nullptr;
	}
	Lion(AnimalWorld* animal, Continent* cont, char* n, int p) 
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		animal->AddCarnivore(this);
		continent = cont;
		power = p;
	}
	void Print() 
	{
		cout << "Name: " << name << endl;
		cout << "Weight: " << power << endl;
		cout << "Continent: " << GetContinent();
	}
	virtual void EatHerbivore(Herbivore* obj) 
	{
		if (continent->GetContinent() != obj->GetContinent()) 
		{
			cout << "These animals are from different continents!!" << endl;
		}
		else {
			cout << "-1 " << obj->GetNameH() << endl;
			cout << "Lion power: " << power << endl;
			cout << "Lion weight: " << obj->GetWeight() << endl;
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
	~Lion() {
		delete continent;
	}
};
class Wolf: public Carnivore
{
private:
	Continent* continent;
public:
	Wolf() {
		power = 0;
		continent = nullptr;
	}
	Wolf(AnimalWorld* animal, Continent* cont, char* n, int p) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		animal->AddCarnivore(this);
		continent = cont;
		power = p;
	}
	void Print() {
		cout << "Name: " << name << endl;
		cout << "Weight: " << power << endl;
		cout << "Continent: " << GetContinent();
	}
	virtual void EatHerbivore(Herbivore* obj) {
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
	~Wolf() {
		delete continent;
	}
};
