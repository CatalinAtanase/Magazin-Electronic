#include "Telefon.h"

Telefon::Telefon() {
	diagonala = 0;
	capacitateBaterie = 0;
	nrCamere = 1;
	waterproof = false;
	retea = "4G";
	procesor = "hexa-core";
	this->setAttributes();
};

//constructor cu parametri
Telefon::Telefon(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
	bool isSmart, Culoare culoare, float diagonala, int capacitateBaterie, int nrCamere, bool waterproof,
	string retea, string procesor) :Electronic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare) {
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

void Telefon::setAttributes() {
	float fInput;
	string sInput;
	int iInput;

	cout << "\nIntroduceti nume: ";
	cin >> sInput;
	setNume(sInput);

	cout << "\nIntroduceti cod: ";
	cin >> iInput;
	setCod(iInput);

	cout << "\nIntroduceti firma: ";
	cin >> sInput;
	setFirma(sInput);

	cout << "\nIntroduceti descriere: ";
	cin >> sInput;
	setFirma(sInput);

	cout << "\nIntroduceti pret: ";
	cin >> fInput;
	setPret(fInput);

	cout << "\nIntroduceti greutate: ";
	cin >> fInput;
	setPret(fInput);

	cout << "\nIntroduceti diagonala: ";
	cin >> fInput;
	setPret(fInput);

	/*cout << "\nIntroduceti capacitate baterie: ";
	cin >> iInput;
	setBaterie(iInput)*/;

	//cout << "\nIntroduceti numar camere: ";
	//cin >> iInput;
	//setNr(iInput);

	cout << "\nIntroduceti procesor: ";
	cin >> sInput;
	setProcesor(sInput);
}


//string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
//bool isSmart, Culoare culoare, float diagonala, int capacitateBaterie, int nrCamere, bool waterproof,
//string retea, string procesor) :Electronic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare)
string Telefon::toString() {
	return "Tip Produs: Teleofon\nNume: " + this->getNume() +
		"\ncod: " + to_string(this->getCod()) +
		"\nFirma: " + this->getFirma() +
		"\nDescriere: " + this->getDescriere() +
		"\nPret: " + to_string(this->getPret()) +
		"\nGrantie: " + to_string(this->getGarantie()) +
		"\nIn stoc: " + (this->isInStoc() ? "Da" : "Nu") +
		"\nPret Redus: " + (this->isInStoc() ? "Da" : "Nu") +
		"\nGreutate: " + to_string(this->getGreutate()) +
		"\nSmart: " + (this->IsSmart() ? "Da" : "Nu") +
		"\nProcesor: " + this->getProcesor() +
		"\nDiagonala: " + to_string(this->getDiagonala()) +
		"\n";
}

