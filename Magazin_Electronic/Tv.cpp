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
	if (tipDisplay != " ") {
		this->tipDisplay = tipDisplay;
	}
	else tipDisplay = "LCD";
	if (rezolutie != " ") {
		this->rezolutie = rezolutie;
	}
	else rezolutie = "HD";
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
string Tv::getTipDisplay() {
	return tipDisplay;
}
string Tv::getRezolutie() {
	return rezolutie;
}

//setter
void Tv::setDiagonala(float diagonala) {
	if (diagonala >= 0) {
		this->diagonala = diagonala;
	}
}
void Tv::setTipDisplay(string tipDisplay) {
	if (tipDisplay != " ") {
		this->tipDisplay = tipDisplay;
	}
}
void Tv::setRezolutie(string rezolutie) {
	if (rezolutie != " ") {
		this->rezolutie = rezolutie;
	}
}

//operator -=
Produs Tv::operator-=(int x) {
	diagonala -= x;
	return *this;
}

void Tv::setAttributes() {
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
	cin >> sInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setFirma(sInput);
	};

	cout << "\nIntroduceti descriere: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setDescriere(sInput);

	//string clasaEnergetica, float diagonala, string tipDisplay, string rezolutie
	cout << "\nIntroduceti clasa energetica: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setClasaEnergetica(sInput);

	cout << "\nIntroduceti diagonala: ";
	cin >> fInput;
	if (!cin.good()) {
		cin.clear();
		cin.ignore(9999, '\n');
	}
	else {
		setDiagonala(fInput);
	};

	cout << "\nIntroduceti tip display: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setTipDisplay(sInput);

	cout << "\nIntroduceti rezolutie: ";
	getline(cin, sInput);
	getline(cin, sInput);
	setRezolutie(sInput);
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
		"\Rezolutie: " + this->getRezolutie() +
		"\n";
}
