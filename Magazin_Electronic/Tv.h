#pragma once
#include "Casnic.h"

class Tv : public Casnic {
protected:
	float diagonala;
	string tipDisplay;
	string rezolutie;

public:
	Tv();
	Tv(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float putere, string clasaEnergetica, float diagonala, string tipDisplay, string rezolutie);
	~Tv();
	Tv(Tv& tv);

	void operator=(Tv& tv);

	float getDiagonala();
	string getTipDisplay();
	string getRezolutie();

	void setDiagonala(float diagonala);
	void setTipDisplay(string tipDisplay);
	void setRezolutie(string rezolutie);

	virtual string toString();
	virtual void setAttributes();
};

