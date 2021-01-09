#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Produs.h"


class User {
protected:
	string nume;
	string prenume;
	string email;
	vector<Produs> cos;

	//constructori implicit
public:
	User();
	User(string nume, string prenume, string email, vector<Produs> cos);
	~User();
	User(User& u);
	void operator=(User u);
	string getEmail();
	string getNume();
	void setEmail(string email);
	void setNume(string nume);
};

