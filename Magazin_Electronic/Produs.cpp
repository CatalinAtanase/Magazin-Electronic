#include "Produs.h"
#include <iostream>
#include <string>
using namespace std;

Produs::Produs() {
	this->nume = "Produs fara nume";
	this->cod = 0;
	this->firma = "Firma";
	this->descriere = "Acest produs nu are descriere.";
	this->pret = 0;
	this->garantie = 0;
	this->inStoc = false;
	this->isRedus = false;
};

Produs::Produs(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus) {
	if (nume != " ") {
		this->nume = nume;
	}
	else {
		this->nume = "Produs fara nume";
	}

	if (cod != 0) {
		this->cod = cod;
	}
	else {
		this->cod = 0;
	}

	if (firma != " ") {
		this->firma = firma;
	}
	else {
		this->firma = "Firma neinregistrata.";
	}

	if (descriere != " ") {
		this->descriere = descriere;
	}
	else {
		this->descriere = "Acest produs nu are descriere.";
	}

	if (pret >= 0)
		this->pret = pret;
	else
		this->pret = 0;

	if (garantie > 0) {
		this->garantie = garantie;
	}
	else {
		this->garantie = 0;
	}

	this->inStoc = inStoc;
	this->isRedus = isRedus;
};

//constructor de copiere
Produs::Produs(const Produs &p) {
	this->nume = p.nume;
	this->cod = p.cod;
	this->firma = p.firma;
	this->descriere = p.descriere;
	this->pret = p.pret;
	this->garantie = p.garantie;
	this->inStoc = p.inStoc;
	this->isRedus = p.isRedus;
}

//operator =
void Produs::operator=(Produs p) {
	this->nume = p.nume;
	this->cod = p.cod;
	this->firma = p.firma;
	this->descriere = p.descriere;
	this->pret = p.pret;
	this->garantie = p.garantie;
	this->inStoc = p.inStoc;
	this->isRedus = p.isRedus;
}

//getteri
float Produs::getPret() {
	return pret;
}

int Produs::getCod() {
	return cod;
}

string Produs::getNume() {
	return nume;
}

bool Produs::isInStoc() {
	return inStoc;
}

int Produs::getGarantie() {
	return garantie;
}
bool Produs::isIsRedus() {
	return isRedus;
}
string Produs::getFirma() {
	return this->firma;
}

string Produs::getDescriere() {
	return this->descriere;
}

//setteri
void Produs::setPret(float pret) {
	if (pret >= 0) {
		this->pret = pret;
	}
}

void Produs::setCod(int cod) {
	if (cod != 0) {
		this->cod = cod;
	}
}

void Produs::setNume(string nume) {
	if (nume != " ") {
		this->nume = nume;
	}
}

void Produs::setInStoc(bool inStoc) {
	this->inStoc = inStoc;
}

void Produs::setFirma(string firma) {
	this->firma = firma;
}

void Produs::setDescriere(string descriere) {
	if (descriere != " ") {
		this->descriere = descriere;
	}
}

void Produs::setIsRedus(bool isRedus) {
	this->isRedus = isRedus;
}

void Produs::setGarantie(int garantie) {
	if (garantie != 0) {
		this->garantie = garantie;
	}
}
//operator +=
Produs Produs::operator+=(int x) {
	pret += x;
	return *this;
}


string Produs::toString() {
	return "Produs\n";
}



void Produs::setAttributes() {

}

Produs Produs::operator-=(int x) {
	return *this;
}

ifstream& operator>>(ifstream& fin, Produs& p)
{
	fin.read((char*)&p.cod, sizeof(int));
	fin.read((char*)&p.nume, sizeof(string));
	fin.read((char*)&p.firma, sizeof(string));
	fin.read((char*)&p.descriere, sizeof(string));
	fin.read((char*)&p.pret, sizeof(float));
	fin.read((char*)&p.garantie, sizeof(int));
	fin.read((char*)&p.inStoc, sizeof(bool));
	fin.read((char*)&p.isRedus, sizeof(bool));

	return fin;
}

//destructor
Produs::~Produs()
{

};
