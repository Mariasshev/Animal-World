#pragma once
#include <iostream>
using namespace std;

class Continent {
protected:
	char* name;
	int temperature;
	double square;
public:
	Continent() {
		name = nullptr;
		temperature = 0;
		square = 0;
	}
	Continent(const char* n, int t, double s) {
		name = new char[strlen(n)+1];
		strcpy_s(name, strlen(n) + 1, n);
		temperature = t;
		square = s;
	}
	void Input() {
		cout << "Enter continent name: ";
		char buff[15];
		cin >> buff;
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter temperature: ";
		cin >> temperature;
		cout << "Enter square: ";
		cin >> square;
	}
	virtual void Print() {
		cout << "Continent: " << name << endl;
		cout << "Square: " << square << endl;
		cout << "temperature: " << temperature << endl;
	}
	char* GetContinent() {
		return name;
	}
	virtual ~Continent() {
		delete name;
	}
};

class Afrika : public Continent
{
private:
	Herbivore* herbivore;
	Carnivore* carnivore;
public:
	Afrika() = default;
	Afrika(const char* n, int t, double s) :Continent(n, t, s) {}
	virtual void Print() {
		cout << "Continent: " << name << endl;
		cout << "Square: " << square << endl;
		cout << "temperature: " << temperature << endl;
	}
	char* GetContinent() {
		return name;
	}
	~Afrika() {
		delete herbivore;
		delete carnivore;
	}
};

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

class Herbivore {
protected:
	char* name;
	double weight;
	bool isLife;
public:
	Herbivore() {
		weight = 0;
		isLife = false;
		name = nullptr;
	}
	Herbivore(double w, bool life, char* n) {
		weight = w;
		isLife = life;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	virtual void EatGrass() {
		weight += 10;
	}
	virtual void Print() = 0;

	void Input() {
		cout << "Enter animal: ";
		char buff[15];
		cin >> buff;
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter weight: ";
		cin >> weight;
		cout << "Is this animal alive? ";
		cin >> isLife;
	}
	char* GetNameH() {
		return name;
	}
	double GetWeight(){
		return weight;
	}
	bool GetLife() {
		return isLife;
	}
	virtual char* GetContinent() const = 0;

	void SetNameH(char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetWeight(double w) {
		weight = w;
	}
	void SetLife(bool l) {
		isLife = l;
	}

};

class Carnivore {
protected:
	char* name;
	int power;
public:
	Carnivore() {
		power = 0;
		name = nullptr;
	}
	Carnivore(int p, char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		power = p;
	}
	virtual void Eat(Herbivore* herb) const = 0;
	virtual void Print() = 0;
	void Input() {
		cout << "Enter animal: ";
		char buff[15];
		cin >> buff;
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter power: ";
		cin >> power;
	}
	char* GetNameC() {
		return name;
	}
	int GetPower() {
		return power;
	}

	virtual char* GetContinent() const = 0;

	void SetNameC(char* n) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void SetPower(double p) {
		power = p;
	}
};

class Wildbeest: public Herbivore
{
private:
	Continent* continent;
public:
	Wildbeest() {
		weight = 0;
		isLife = false;
	}
	Wildbeest(AnimalWorld* animal, Continent* cont, char* n, double w, bool life) {
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
	~Wildbeest() {
		delete continent;
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