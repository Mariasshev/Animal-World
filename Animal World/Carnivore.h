#pragma once
#include "Herbivore.h"
class Carnivore {
protected:
	char* name;
	int power;
public:
	Carnivore();
	Carnivore(int p, char* n);
	virtual void Eat(Herbivore* herb) const = 0;
	virtual void Print() = 0;
	void Input();
	char* GetNameC();
	int GetPower();

	virtual char* GetContinent() const = 0;

	void SetNameC(char* n);
	void SetPower(double p);
};


