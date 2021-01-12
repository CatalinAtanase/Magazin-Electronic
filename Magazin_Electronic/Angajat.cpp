#include "Angajat.h"

Angajat::Angajat() : User() {
	salariu = 0;
	dataAngajare = "01.01.2000";
	post = "Manager";
}
//constructor cu parametri
Angajat::Angajat(string nume, string prenume, string email, vector<Produs *> cos, float salariu, string dataAngajare,
	string post) :User(nume, prenume, email, cos) {
	if (salariu >= 0) {
		this->salariu = salariu;
	}
	else this->salariu = 0;

	if (dataAngajare != " ") {
		this->dataAngajare = dataAngajare;
	}
	else this->dataAngajare = "1 Ianuarie 2010";

	if (post != " ") {
		this->post = post;
	}
	else this->post = "Manager";
	
}

//destructor
Angajat::~Angajat() {

}

//constructor de copiere
Angajat::Angajat(Angajat& a) :User(a) {
	this->salariu = salariu;
	this->dataAngajare = dataAngajare;
	this->post = post;
}

//operator =
void Angajat::operator=(Angajat a) {
	this->User::operator=(a);
	this->salariu = salariu;
	this->dataAngajare = dataAngajare;
	this->post = post;
}

//getter
float Angajat::getSalariu() {
	return salariu;
}
string Angajat::getDataAngajare() {
	return dataAngajare;
}
string Angajat::getPost() {
	return post;
}

//setter
void Angajat::setSalariu(float salariu) {
	if (salariu >= 0) {
		this->salariu = salariu;
	}
}
void Angajat::setDataAngajare(string dataAngajare) {
	if (dataAngajare != " ") {
		this->dataAngajare = dataAngajare;
	}
}
void Angajat::setPost(string post) {
	if (post != " ") {
		this->post = post;
	}
}

void Angajat::greeting() {
	cout << "Angajat indentificat.\nBine ai venit " + prenume + " " + nume + "!" << endl;
}