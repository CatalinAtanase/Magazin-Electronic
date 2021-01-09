#include "Telefon.h"

Telefon::Telefon() {
	diagonala = 0;
	capacitateBaterie = 0;
	nrCamere = 1;
	waterproof = false;
	retea = "4G";
	procesor = "hexa-core";
};

//constructor cu parametri
Telefon::Telefon(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
	bool isSmart, Culoare culoare, float diagonala, int capacitateBaterie, int nrCamere, bool waterproof,
	string retea, string procesor) {
	this->diagonala = diagonala;
	this->capacitateBaterie = capacitateBaterie;
	this->nrCamere = nrCamere;
	this->waterproof = waterproof;
	this->retea = retea;
	this->procesor = procesor;
}

//destructor
Telefon::~Telefon() {

}

//constructor de copiere
Telefon::Telefon(Telefon& t) :Electronic::Electronic(t) {
	this->diagonala = t.diagonala;
	this->capacitateBaterie = t.capacitateBaterie;
	this->nrCamere = t.nrCamere;
	this->waterproof = t.waterproof;
	this->retea = t.retea;
	this->procesor = t.procesor;
}

//operator=
void Telefon::operator=(Telefon& t) {
	this->Electronic::operator=(t);
	this->diagonala = t.diagonala;
	this->capacitateBaterie = t.capacitateBaterie;
	this->nrCamere = t.nrCamere;
	this->waterproof = t.waterproof;
	this->retea = t.retea;
	this->procesor = t.procesor;
}
//getter
float Telefon::getDiagonala() {
	return diagonala;
}

bool Telefon::isWaterproof() {
	return waterproof;
}

string Telefon::getProcesor() {
	return procesor;
}
//setter
void Telefon::setDiagonala(float diagonala) {
	this->diagonala = diagonala;
}

void Telefon::setWaterproof(bool waterproof) {
	this->waterproof = waterproof;
}

void Telefon::setProcesor(string procesor) {
	this->procesor = procesor;
}

string Telefon::toString() {
	return "Nume: " + this->getNume() +
		"\nFirma: " + this->getFirma() +
		"\nDescriere: " + this->getDescriere() +
		"\nPret: " + to_string(this->getPret()) +
		"\Greutate: " + to_string(this->getGreutate()) +
		"\Procesor: " + this->getProcesor() +
		"\Diagonala: " + to_string(this->getDiagonala()) +
		"\nSmart: " + (this->IsSmart() ? "Da" : "Nu") +
		"\nIn stoc: " + (this->isInStoc() ? "Da" : "Nu") +
		"\n";
}