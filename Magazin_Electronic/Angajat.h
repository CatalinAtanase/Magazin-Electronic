#pragma once
#include "User.h"

class Angajat: public User {
protected:
	float salariu;
	string dataAngajare;
	string post;
public:
	Angajat();
	Angajat(string nume, string prenume, string email, vector<Produs> cos, float salariu, string dataAngajare,
		string post);
	~Angajat();
	Angajat(Angajat& a);
	void operator=(Angajat a);
	float getSalariu();
	string getDataAngajare();
	void setSalariu(float salariu);
	void setDataAngajare(string dataAngajare);
};

