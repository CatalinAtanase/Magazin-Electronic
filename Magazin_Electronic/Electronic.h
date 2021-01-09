#pragma once
#include <iostream>
#include "Produs.h"

using namespace std;

enum class Culoare
{
	pianoBlack, gri, verdeSmarald, albMurdar, auriu, roz
};

class Electronic : public Produs {
protected:
	float greutate;
	bool isSmart;
	Culoare culoare;

public:
	Electronic();
	Electronic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare);
	~Electronic();
	Electronic(Electronic& e);
	void operator=(Electronic e);
	float getGreutate();
	bool IsSmart();
	void setGreutate(float greutate);
	void setIsSmart(bool isSmart);
	string toString();
};

