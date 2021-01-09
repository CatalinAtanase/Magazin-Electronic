#include "Electronic.h"

Electronic::Electronic() : Produs::Produs() {
	greutate = 0;
	isSmart = false;
	culoare = Culoare::pianoBlack;
}

Electronic::Electronic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate, bool isSmart, Culoare culoare) : Produs::Produs(nume,  cod,  firma,  descriere,  pret,  garantie,  inStoc,  isRedus) {
	if (greutate >= 0) {
		this->greutate = greutate;
	}
	else

	this->isSmart = isSmart;
	this->culoare = culoare;
}

//destructor
Electronic::~Electronic() {

}

//constructor de copiere
Electronic::Electronic(Electronic &e) : Produs::Produs(e) {
	this->greutate = e.greutate;
	this->isSmart = e.isSmart;
	this->culoare = e.culoare;
}

//operator =
void Electronic::operator=(Electronic e) {
	this->Produs::operator=(e);
	this->greutate = e.greutate;
	this->isSmart = e.isSmart;
	this->culoare = e.culoare;
}

//getteri
float Electronic::getGreutate() {
	return greutate;
}

bool Electronic::IsSmart() {
	return isSmart;
}

//setteri
void Electronic::setGreutate(float greutate) {
	if (greutate >= 0) {
		this->greutate = greutate;
	}
}

void Electronic::setIsSmart(bool isSmart) {
	this->isSmart = isSmart;
}

string Electronic::toString() {
	return "Casnic";
}