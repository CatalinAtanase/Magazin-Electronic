#include <iostream>
#include <string>
using namespace std;

class Produs {
protected:
	string nume;
	int cod;
	string firma;
	string descriere;
	float pret;
	int garantie;
	bool inStoc;
	bool isRedus;

	//constructori implicit
public:
	Produs() {
		this->nume = "Produs fara nume";
		this->cod = 0;
		this->firma = " ";
		this->descriere = "Acest produs nu are descriere.";
		this->pret = 0;
		this->garantie = 0;
		this->inStoc = false;
		this->isRedus = false;
	}

	//constructor  cu parametri
	Produs(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus) {
		if (nume != " ") {
			this->nume = nume;
		}
		else {
			this->nume = "Produs fara nume"
		}

		if (cod != " ") {
			this->cod = cod;
		}
		else {
			this->cod = "Acest produs nu are cod."
		}

		if (firma != " ") {
			this->firma = firma;
		}
		else {
			this->firma = "Firma neinregistrata."
		}

		if (descriere != " ") {
			this->descriere = descriere;
		}
		else {
			this->descriere = "Acest produs nu are descriere."
		}

		if (pret >= 0)
			this->pret = pret;
		else
			this->pret = 0;

		if (garantie > 0) {
			this->garantie = garantie;
		}
		else {
			this->garantie = 0;
		}

		this->inStoc = inStoc;
		this->isRedus = isRedus;
	}

	//constructor de copiere
	Produs(Produs &p) {

		this->nume = p.nume;
		this->cod = p.cod;
		this->firma = p.firma;
		this->descriere = p.descriere;
		this->pret = p.pret;
		this->garantie = p.garantie;
		this->inStoc = p.inStoc;
		this->isRedus = p.isRedus;
	}

	//operator =
	void operator=(Produs p) {
		this->nume = p.nume;
		this->cod = p.cod;
		this->firma = p.firma;
		this->descriere = p.descriere;
		this->pret = p.pret;
		this->garantie = p.garantie;
		this->inStoc = p.inStoc;
		this->isRedus = p.isRedus;
	}


	//destructor
	~Produs()
	{

	}
};

void main() {
	Produs p1; //apel constructor implicit
	Produs p2("Aspirator-proba", 1001, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false); //apel constructor cu parametri
	Produs p3("Aspirator", 1002, "Rowenta", "Aspiratorul vietii tale", 1635, 2, true, false);
	Produs p4(p2); //apel constructor de copiere
	//Produs p4 = p3; //apel operator -

}