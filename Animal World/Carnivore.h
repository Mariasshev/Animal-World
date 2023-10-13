#pragma once
#include "Herbivore.h"
class Carnivore {
protected:
	char* name;
	int power;
public:
	Carnivore();
	Carnivore(int p, char* n);
	virtual void Eat(Herbivore* herb) = 0;
	virtual void Print() = 0;

	void Input();
	char* GetNameC();
	int GetPower();

	void SetNameC(char* n);
	void SetPower(double p);
};


