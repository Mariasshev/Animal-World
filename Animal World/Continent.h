#pragma once
class Continent {
protected:
	char* name;
	int temperature;
	double square;
public:
	Continent();
	Continent(const char* n, int t, double s);
	void Input();
	virtual void Print();
	char* GetContinent();
	virtual ~Continent();
};

