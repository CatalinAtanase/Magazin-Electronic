#include "Casnic.h"

Casnic::Casnic() : Electronic() {
	putere = 365;
	clasaEnergetica = "A++";
}

Casnic::Casnic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
	bool isSmart, Culoare culoare, float putere, string clasaEnergetica) :Electronic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare) {
	if (putere >= 0) {
		this->putere = putere;
	}
	else
		this->putere = 0;
	if (clasaEnergetica != " ") {
		this->clasaEnergetica = clasaEnergetica;
	}
}

//destructor
Casnic::~Casnic() {

}

//constructor de copiere
Casnic::Casnic(Casnic& c) :Electronic(c) {
	this->putere = c.putere;
	this->clasaEnergetica = c.clasaEnergetica;
}

//operator=
void Casnic::operator=(Casnic& c) {
	this->Electronic::operator=(c);
	this->putere = c.putere;
	this->clasaEnergetica = c.clasaEnergetica;
}

//getter
string Casnic::getClasaEnergetica() {
	return clasaEnergetica;
}

float Casnic::getPutere() {
	return putere;
}

//setter
void Casnic::setClasaEnergetica(string clasaEnergetica) {
	if (clasaEnergetica != " ") {
		this->clasaEnergetica = clasaEnergetica;
	}
}

void Casnic::setPutere(float putere) {
	if (putere >= 0) {
		this->putere = putere;
	}
}

string Casnic::toString() {
	return "Casnic";
}

//operator >,<
bool Casnic::operator<(const Casnic c) { return this->pret < c.pret; };
bool Casnic::operator>(const Casnic c) { return this->pret > c.pret; };