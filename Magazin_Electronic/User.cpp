#include "User.h"
#include <sstream>

User::User() {
	this->nume = "User";
	this->prenume = "User";
	this->email = "Email@email.com";
}

//constructor cu parametri
User::User(string nume, string prenume, string email, vector<Produs *> cos) {
	if (nume != " ") {
		this->nume = nume;
	}
	else this->nume = "User";
	if (prenume != " ") {
		this->prenume = prenume;
	}
	else this->prenume = "User";
	if (email != " ") {
		this->email = email;
	}
	else this->email = "Email@email.com";

	this->cos = cos;
}

//destructor
User::~User() {

}

//constructor de copiere
User::User(User& u) {
	this->nume = u.nume;
	this->prenume = u.prenume;
	this->email = u.email;
	/*this->cos = u.cos;*/
	/*for(auto i=u.cos.begin(); i<u.cos.size())*/
	this->cos.assign(u.cos.begin(), u.cos.end());
}

//operator =
void User::operator=(User u) {
	this->nume = u.nume;
	this->prenume = u.prenume;
	this->email = u.email;
	this->cos.assign(u.cos.begin(), u.cos.end());
}

//getter
string User::getEmail() {
	return email;
}
string User::getNume() {
	return nume;
}
string User::getPrenume() {
	return prenume;
}

int User::getCartSize() {
	return cos.size();
}

//setter
void User::setEmail(string email) {
	if (email != " ") {
		this->email = email;
	}
}
void User::setNume(string nume) {
	if (nume != " ") {
		this->nume = nume;
	}
}

void User::setPrenume(string nume) {
	if (nume != " ") {
		this->prenume = nume;
	}
}

void User::greeting() {
	cout << "Bine ai venit " + prenume + " " + nume + "!" << endl;
}

void User::addToCart(Produs* produs) {
	this->cos.push_back(produs);
}

void User::showCart() {
	vector<Produs*>::iterator it;
	cout << "\nAfisare produse din cos." << endl;
	int counter = 1;

	for (it = this->cos.begin(); it != this->cos.end(); it++) {
		cout << counter << ". " << (*it)->toString() << endl;
		counter++;
	}
}

void User::deleteItemFromCart(vector<Produs*>& produseMagazin, int index) {
	produseMagazin.push_back(this->cos[index - 1]);
	this->cos[index - 1] = this->cos.back();
	this->cos.pop_back();
}

string User::prepareOrder() {
	string order;
	vector<Produs*>::iterator it;
	int counter = 1;

	string adresa;
	cout << "Adresa: ";
	cin >> adresa;

	order = "Comanda pentru: " + this->getNume() + " " + this->getPrenume() + "\nProduse comanda: \n";

	for (it = this->cos.begin(); it != this->cos.end(); it++) {
		order += (*it)->toString();
		order += "\n";
	}

	order += "Adresa: ";
	order += adresa;

	return order;
}

