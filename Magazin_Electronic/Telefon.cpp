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
	if (diagonala != 0) {
		this->diagonala = diagonala;
	}
	else diagonala = 0;
	if (capacitateBaterie != 0) {
		this->capacitateBaterie=capacitateBaterie;
	}
	else capacitateBaterie = 0;
	if (nrCamere >= 0 && nrCamere <= 4) {
		this->nrCamere = nrCamere;
	}
	else nrCamere = 0;
	this->waterproof = waterproof;
	if (retea != " ") {
		this->retea = retea;
	}
	else retea = "4G";
	if (procesor != " ") {
		this->procesor = procesor;
	}
	else procesor = "Hexa Core";	
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
int Telefon::getCapacitateBaterie() {
	return capacitateBaterie;
}
int Telefon::getNrCamere() {
	return nrCamere;
}
string Telefon::getRetea() {
	return retea;
}
string Telefon::getProcesor() {
	return procesor;
}

//setter
void Telefon::setDiagonala(float diagonala) {
	if (diagonala != 0) {
		this->diagonala = diagonala;
	}
}

void Telefon::setWaterproof(bool waterproof) {
	this->waterproof = waterproof;
}

void Telefon::setProcesor(string procesor) {
	if (procesor != " ") {
		this->procesor = procesor;
	}
}

void Telefon::setRetea(string retea) {
	if (retea != " ") {
		this->retea = retea;
	}
}
void Telefon::setNrCamere(int nrCamere) {
	if (nrCamere >= 0 && nrCamere <= 4) {
		this->nrCamere = nrCamere;
	}
}
void Telefon::setCapacitateBaterie(int capacitateBaterie) {
	if (capacitateBaterie != 0) {
		this->capacitateBaterie = capacitateBaterie;
	}
}

//operator -=
Produs Telefon::operator-=(int x) {
	capacitateBaterie -= x;
	return *this;
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

