#pragma once
#include <iostream>
#include "Electronic.h"

using namespace std;

class Telefon: public Electronic {
private:
	float diagonala;
	int capacitateBaterie;
	int nrCamere;
	bool waterproof;
	string retea;
	string procesor;

public:
	Telefon();
	Telefon(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float diagonala, int capacitateBaterie, int nrCamere, bool waterproof,
		string retea, string procesor);
	~Telefon();
	Telefon(Telefon& t);
	void operator=(Telefon& t);
	float getDiagonala();
	bool isWaterproof();
	string getProcesor();
	void setDiagonala(float diagonala);
	void setWaterproof(bool waterproof);
	void setProcesor(string procesor);
	virtual string toString();
};

