#pragma once
#include <iostream>
#include <string>
#include "IProdus.h"
#include<fstream>

using namespace std;

class Produs : public IProdus {
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
	int getGarantie();
	bool isInStoc();
	bool isIsRedus();

	void setPret(float pret);
	void setCod(int cod);
	void setDescriere(string descriere);
	void setNume(string nume);
	void setInStoc(bool inStoc);
	void setFirma(string firma);
	void setIsRedus(bool isRedus);
	void setGarantie(int garantie);
	virtual string toString();
	virtual Produs operator-=(int x);
	virtual void setAttributes();
	//operator +=
	Produs operator+=(int x);
	friend ifstream& operator>>(ifstream& fin, Produs& p);
};

