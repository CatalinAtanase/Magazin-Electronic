#pragma once
#include <iostream>
#include "Electronic.h"

class Casnic: public Electronic {
protected:
	float putere;
	string clasaEnergetica;
public:
	Casnic();
	Casnic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float putere, string clasaEnergetica);
	~Casnic();
	Casnic(Casnic& c);

	void operator=(Casnic& c);
	string getClasaEnergetica();
	float getPutere();
	void setPutere(float putere);
	void setClasaEnergetica(string clasaEnergetica);
	virtual string toString();
};

