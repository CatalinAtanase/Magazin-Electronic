#include "Frigider.h"

Frigider::Frigider() : Casnic() {
	nrUsi = 1;
	capacitate = 0;
	congelator = true;
}

//constructor cu parametri
Frigider::Frigider(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
	bool isSmart, Culoare culoare, float putere, string clasaEnergetica, int nrUsi, int capacitate, bool congelator) :Casnic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare, putere, clasaEnergetica) {
	if (nrUsi >= 0) {
		this->nrUsi = nrUsi;
	}
	else this->nrUsi = 1;

	if (capacitate >= 0) {
		this->capacitate = capacitate;
	}
	else this->capacitate = 0;

	this->congelator = congelator;

}

//destructor
Frigider::~Frigider() {

}

//constructor de copiere
Frigider::Frigider(Frigider& f) :Casnic(f) {
	this->nrUsi = f.nrUsi;
	this->capacitate = f.capacitate;
	this->congelator = f.congelator;
}

//operator=
void Frigider::operator=(Frigider& f) {
	this->Casnic::operator=(f);
	this->nrUsi = f.nrUsi;
	this->capacitate = f.capacitate;
	this->congelator = f.congelator;
}

//getter
int Frigider::getNrUsi() {
	return nrUsi;
}
int Frigider::getCapacitate() {
	return capacitate;
}
bool Frigider::getCongelator() {
	return congelator;
}
//setter
void Frigider::setNrUsi(int nrUsi) {
	if (nrUsi >= 0) {
		this->nrUsi = nrUsi;
	}
}
void Frigider::setCapacitate(int capacitate) {
	if (capacitate >= 0) {
		this->capacitate = capacitate;
	}
}
void Frigider::setCongelator(bool congelator) {
	this->congelator = congelator;
}

//operator -=
Produs Frigider::operator-=(int x) {
	capacitate-= x;
	return *this;
}


void Frigider::setAttributes() {
	float fInput;
	string sInput;
	int iInput;

	cout << "\nIntroduceti nume: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setNume(sInput);

	cout << "\nIntroduceti cod: ";
	cin >> iInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setCod(iInput);
	};

	cout << "\nIntroduceti firma: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setFirma(sInput);

	cout << "\nIntroduceti descriere: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setDescriere(sInput);

	cout << "\nIntroduceti pret: ";
	cin >> fInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setPret(fInput);
	};


	cout << "\nIntroduceti greutate: ";
	cin >> fInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setGreutate(fInput);
	};

	cout << "\nIntroduceti clasa energetica: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setClasaEnergetica(sInput);

	cout << "\nIntroduceti numar usi: ";
	cin >> iInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setNrUsi(iInput);
	};

	cout << "\nIntroduceti capacitate: ";
	cin >> iInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setCapacitate(iInput);
	};
}

string Frigider::toString() {
	return "Nume: " + this->getNume() +
		"\nFirma: " + this->getFirma() +
		"\nDescriere: " + this->getDescriere() +
		"\nPret: " + to_string(this->getPret()) +
		"\nGreutate: " + to_string(this->getGreutate()) +
		"\nClasa energetica: " + this->getClasaEnergetica() +
		"\nNumar usi: " + to_string(this->getNrUsi()) +
		"\nSmart: " + (this->IsSmart() ? "Da" : "Nu") +
		"\n";
}
