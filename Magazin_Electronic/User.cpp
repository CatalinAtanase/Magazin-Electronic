#include "User.h"

User::User() {
	this->nume = "User";
	this->prenume = "User";
	this->email = "Email@email.com";
}

//constructor cu parametri
User::User(string nume, string prenume, string email, vector<Produs> cos) {
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