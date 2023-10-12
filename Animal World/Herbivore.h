#pragma once
class Herbivore {
protected:
	char* name;
	double weight;
	bool isLife;
public:
	Herbivore();
	Herbivore(double w, bool life, char* n);
	virtual void EatGrass();
	virtual void Print() = 0;

	void Input();
	char* GetNameH();
	double GetWeight();
	bool GetLife();
	virtual char* GetContinent() const = 0;

	void SetNameH(char* n);
	void SetWeight(double w);
	void SetLife(bool l);

};


