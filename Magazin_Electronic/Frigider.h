#pragma once
#include "Casnic.h"

class Frigider : public Casnic {
protected:
	int nrUsi;
	int capacitate;
	bool congelator;

public:
	Frigider();
	Frigider(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float putere, string clasaEnergetica, int nrUsi, int capacitate, bool congelator);
	~Frigider();
	Frigider(Frigider& f);
	void operator=(Frigider& f);

	int getNrUsi();
	int getCapacitate();
	bool getCongelator();

	void setNrUsi(int nrUsi);
	void setCapacitate(int capacitate);
	void setCongelator(bool congelator);

	virtual string toString();
	virtual void setAttributes();
};

