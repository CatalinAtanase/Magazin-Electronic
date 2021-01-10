#include "Tv.h"

Tv::Tv() : Casnic() {
	diagonala = 40;
	tipDisplay = "LCD";
	rezolutie = "1920x1080";
}

//constructor cu parametri
Tv::Tv(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
	bool isSmart, Culoare culoare, float putere, string clasaEnergetica, float diagonala, string tipDisplay, string rezolutie) :Casnic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare, putere, clasaEnergetica) {
	if (diagonala >= 0) {
		this->diagonala = diagonala;
	}
	else this->diagonala = 0;
	this->tipDisplay = tipDisplay;
	this->rezolutie = rezolutie;
}

//destructor
Tv::~Tv() {

}

//constructor de copiere
Tv::Tv(Tv& tv) :Casnic(tv) {
	this->diagonala = tv.diagonala;
	this->tipDisplay = tv.tipDisplay;
	this->rezolutie = tv.rezolutie;
}

//operator=
void Tv::operator=(Tv& tv) {
	this->Casnic::operator=(tv);
	this->diagonala = tv.diagonala;
	this->tipDisplay = tv.tipDisplay;
	this->rezolutie = tv.rezolutie;
}

//getter
float Tv::getDiagonala() {
	return diagonala;
}
//setter
void Tv::setDiagonala(float diagonala) {
	this->diagonala = diagonala;
}

string Tv::toString() {
	return "Nume: " + this->getNume() +
		"\nFirma: " + this->getFirma() +
		"\nDescriere: " + this->getDescriere() +
		"\nPret: " + to_string(this->getPret()) +
		"\nGreutate: " + to_string(this->getGreutate()) +
		"\nClasa energetica: " + this->getClasaEnergetica() +
		"\nDiagonala: " + to_string(this->getDiagonala()) +
		"\nSmart: " + (this->IsSmart() ? "Da" : "Nu") +
		"\nIn stoc: " + (this->isInStoc() ? "Da" : "Nu") +
		"\n";
}
