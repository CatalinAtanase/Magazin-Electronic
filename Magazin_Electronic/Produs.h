#pragma once
#include <iostream>
#include <string>
#include "IProdus.h"

using namespace std;

class Produs : IProdus {
protected:
	string nume;
	int cod;
	string firma;
	string descriere;
	float pret;
	int garantie;
	bool inStoc;
	bool isRedus;

public:
	Produs();
	~Produs();

	Produs(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus);
	Produs(const Produs& p);

	void operator=(Produs p);
	float getPret();
	int getCod();
	string getFirma();
	string getNume();
	string getDescriere();
	bool isInStoc();
	void setPret(float pret);
	void setCod(int cod);
	void setNume(string nume);
	void setInStoc(bool inStoc);
	string toString();
};

