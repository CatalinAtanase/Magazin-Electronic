#include <iostream>
#include <string>
#include <vector>
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
			this->nume = "Produs fara nume";
		}

		if (cod != 0) {
			this->cod = cod;
		}
		else {
			this->cod = 0;
		}

		if (firma != " ") {
			this->firma = firma;
		}
		else {
			this->firma = "Firma neinregistrata.";
		}

		if (descriere != " ") {
			this->descriere = descriere;
		}
		else {
			this->descriere = "Acest produs nu are descriere.";
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
	Produs(const Produs &p) {
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

	//getteri
	float getPret() {
		return pret;
	}

	int getCod() {
		return cod;
	}

	string getNume() {
		return nume;
	}

	bool isInStoc() {
		return inStoc;
	}

	//setteri
	void setPret(float pret) {
		if (pret >= 0) {
			this->pret = pret;
		}
	}

	void setCod(int cod) {
		if (cod != 0) {
			this->cod = cod;
		}
	}

	void setNume(string nume) {
		if (nume != " ") {
			this->nume = nume;
		}
	}

	void setInStoc(bool inStoc) {
		this->inStoc = inStoc;
	}


	//destructor
	~Produs()
	{

	}
};

enum class Culoare
{
	pianoBlack, gri, verdeSmarald, albMurdar, auriu, roz
};

class Electronic : public Produs {
protected:
	float greutate;
	bool isSmart;
	Culoare culoare;
public:
	//constructor implicit
	Electronic() : Produs() {
		greutate = 0;
		isSmart = false;
		culoare = Culoare::pianoBlack;
	}

	//constructor cu parametri
	Electronic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare) : Produs(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus) {
		if (greutate >= 0) {
			this->greutate = greutate;
		}
		else
			this->greutate = 0;

		this->isSmart = isSmart;
		this->culoare = culoare;
	}
	//destructor
	~Electronic() {

	}

	//constructor de copiere
	Electronic(Electronic &e) : Produs(e) {
		this->greutate = e.greutate;
		this->isSmart = e.isSmart;
		this->culoare = e.culoare;
	}

	//operator =
	void operator=(Electronic e) {
		this->Produs::operator=(e);
		this->greutate = e.greutate;
		this->isSmart = e.isSmart;
		this->culoare = e.culoare;
	}

	//getteri
	float getGreutate() {
		return greutate;
	}

	bool isIsSmart() {
		return isSmart;
	}

	//setteri
	void setGreutate(float greutate) {
		if (greutate >= 0) {
			this->greutate = greutate;
		}
	}

	void setIsSmart(bool isSmart) {
		this->isSmart = isSmart;
	}
};

class Casnic : public Electronic {
protected:
	float putere;
	string clasaEnergetica;
public:
	//constructor implicit
	Casnic() : Electronic() {
		putere = 365;
		clasaEnergetica = "A++";
	}

	//constructor cu parametri
	Casnic(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float putere, string clasaEnergetica) :Electronic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare) {
		if (putere >= 0) {
			this->putere = putere;
		}
		else
			this->putere = 0;
		this->clasaEnergetica = clasaEnergetica;
	}

	//destructor
	~Casnic() {

	}

	//constructor de copiere
	Casnic(Casnic &c) :Electronic(c) {
		this->putere = c.putere;
		this->clasaEnergetica = c.clasaEnergetica;
	}

	//operator=
	void operator=(Casnic&c) {
		this->Electronic::operator=(c);
		this->putere = c.putere;
		this->clasaEnergetica = c.clasaEnergetica;
	}

	//getter
	string getClasaEnergetica() {
		return clasaEnergetica;
	}
	//setter
	void setClasaEnergetica(string clasaEnergetica) {
		this->clasaEnergetica = clasaEnergetica;
	}
};

class Telefon : public Electronic {
protected:
	float diagonala;
	int capacitateBaterie;
	int nrCamere;
	bool waterproof;
	string retea;
	string procesor;
public:
	//constructor implicit
	Telefon() : Electronic() {
		diagonala = 0;
		capacitateBaterie = 0;
		nrCamere = 1;
		waterproof = false;
		retea = "4G";
		procesor = "hexa-core";
	}

	//constructor cu parametri
	Telefon(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
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
	~Telefon() {

	}

	//constructor de copiere
	Telefon(Telefon &t) :Electronic(t) {
		this->diagonala = t.diagonala;
		this->capacitateBaterie = t.capacitateBaterie;
		this->nrCamere = t.nrCamere;
		this->waterproof = t.waterproof;
		this->retea = t.retea;
		this->procesor = t.procesor;
	}

	//operator=
	void operator=(Telefon&t) {
		this->Electronic::operator=(t);
		this->diagonala = t.diagonala;
		this->capacitateBaterie = t.capacitateBaterie;
		this->nrCamere = t.nrCamere;
		this->waterproof = t.waterproof;
		this->retea = t.retea;
		this->procesor = t.procesor;
	}
	//getter
	float getDiagonala() {
		return diagonala;
	}

	bool isWaterproof() {
		return waterproof;
	}

	string getProcesor() {
		return procesor;
	}
	//setter
	void setDiagonala(float diagonala) {
		this->diagonala = diagonala;
	}

	void setWaterproof(bool waterproof) {
		this->waterproof = waterproof;
	}

	void setProcesor(string procesor) {
		this->procesor = procesor;
	}
};

class Tv : public Casnic {
protected:
	float diagonala;
	string tipDisplay;
	string rezolutie;

public:
	//constructor implicit
	Tv() : Casnic() {
		diagonala = 40;
		tipDisplay = "LCD";
		rezolutie = "1920x1080";
	}

	//constructor cu parametri
	Tv(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
		bool isSmart, Culoare culoare, float putere, string clasaEnergetica, float diagonala, string tipDisplay, string rezolutie) :Casnic(nume, cod, firma, descriere, pret, garantie, inStoc, isRedus, greutate, isSmart, culoare, putere, clasaEnergetica) {
		if (diagonala >= 0) {
			this->diagonala = diagonala;
		}
		else this->diagonala = 0;
		this->tipDisplay = tipDisplay;
		this->rezolutie = rezolutie;
	}

	//destructor
	~Tv() {

	}

	//constructor de copiere
	Tv(Tv &tv) :Casnic(tv) {
		this->diagonala = tv.diagonala;
		this->tipDisplay = tv.tipDisplay;
		this->rezolutie = tv.rezolutie;
	}

	//operator=
	void operator=(Tv&tv) {
		this->Casnic::operator=(tv);
		this->diagonala = tv.diagonala;
		this->tipDisplay = tv.tipDisplay;
		this->rezolutie = tv.rezolutie;
	}

	//getter
	float getDiagonala() {
		return diagonala;
	}
	//setter
	void setDiagonala(float diagonala) {
		this->diagonala = diagonala;
	}
};

class Frigider : public Casnic {
protected:
	int nrUsi;
	int capacitate;
	bool congelator;

public:
	//constructor implicit
	Frigider() : Casnic() {
		nrUsi = 1;
		capacitate = 0;
		congelator = true;
	}

	//constructor cu parametri
	Frigider(string nume, int cod, string firma, string descriere, float pret, int garantie, bool inStoc, bool isRedus, float greutate,
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
	~Frigider() {

	}

	//constructor de copiere
	Frigider(Frigider &f) :Casnic(f) {
		this->nrUsi = f.nrUsi;
		this->capacitate = f.capacitate;
		this->congelator = f.congelator;
	}

	//operator=
	void operator=(Frigider&f) {
		this->Casnic::operator=(f);
		this->nrUsi = f.nrUsi;
		this->capacitate = f.capacitate;
		this->congelator = f.congelator;
	}

	//getter
	int getNrUsi() {
		return nrUsi;
	}
	//setter
	void setNrUsi(int nrUsi) {
		this->nrUsi = nrUsi;
	}

};

class User {
protected:
	string nume;
	string prenume;
	string email;
	vector<Produs> cos;

	//constructori implicit
public:
	User() {
		this->nume = "User";
		this->prenume = "User";
		this->email = "Email@email.com";
	}

	//constructor cu parametri
	User(string nume, string prenume, string email, vector<Produs> cos) {
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
	~User() {
	
	}

	//constructor de copiere
	User(User &u) {
		this->nume = u.nume;
		this->prenume = u.prenume;
		this->email = u.email;
		/*this->cos = u.cos;*/
		/*for(auto i=u.cos.begin(); i<u.cos.size())*/
		this->cos.assign(u.cos.begin(), u.cos.end());
	}

	//operator =
	void operator=(User u) {
		this->nume = u.nume;
		this->prenume = u.prenume;
		this->email = u.email;
		this->cos.assign(u.cos.begin(), u.cos.end());
	}

	//getter
	string getEmail() {
		return email;
	}
	string getNume() {
		return nume;
	}
	//setter
	void setEmail(string email) {
		if (email != " ") {
			this->email = email;
		}
	}
	void setNume(string nume) {
		if (nume != " ") {
			this->nume = nume;
		}
	}

};

class Angajat :public User {
protected:
	float salariu;
	string dataAngajare;
	string post;
public:
	//constructor implicit
	Angajat() : User() {
		salariu = 0;
		dataAngajare = "01.01.2000";
		post = "Manager";
	}
	//constructor cu parametri
	Angajat(string nume, string prenume, string email, vector<Produs> cos, float salariu, string dataAngajare,
		string post) :User(nume, prenume, email, cos) {
		if (salariu >= 0) {
			this->salariu = salariu;
		}
		else this->salariu = 0;
		this->dataAngajare = dataAngajare;
		this->post = post;
	}

	//destructor
	~Angajat() {

	}

	//constructor de copiere
	Angajat(Angajat &a) :User(a) {
		this->salariu = salariu;
		this->dataAngajare = dataAngajare;
		this->post = post;
	}

	//operator =
	void operator=(Angajat a) {
		this->User::operator=(a);
		this->salariu = salariu;
		this->dataAngajare = dataAngajare;
		this->post = post;
	}

	//getter
	float getSalariu() {
		return salariu;
	}
	string getDataAngajare() {
		return dataAngajare;
	}

	//setter
	void setSalariu(float salariu) {
		if (salariu >= 0) {
			this->salariu = salariu;
		}
	}
	void setDataAngajare(string dataAngajare) {
		if (dataAngajare != " ") {
			this->dataAngajare = dataAngajare;
		}
	}
};

void main() {
	Produs p1; //apel constructor implicit
	Produs p2("Aspirator-proba", 1001, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false); //apel constructor cu parametri
	Produs p3("Aspirator", 1002, "Rowenta", "Aspiratorul vietii tale", 1635, 2, true, false);
	Produs p4(p2); //apel constructor de copiere
	p4 = p3; //apel operator =
	//apel get,set
	cout << "Pret p2 vechi: " << p2.getPret() << endl;
	p2.setPret(69696);
	cout << "Pret p2 nou: " << p2.getPret() << endl;

	Electronic e1; //apel constructor implicit
	Electronic e2("Aspirator-proba", 1005, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 7.2, false, Culoare::roz); //apel constructor cu parametri
	Electronic e3("Aspirator-proba", 1006, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 7.45, false, Culoare::pianoBlack);
	Electronic e4(e2);//apel constructor de copiere
	e4 = e3; //apel operator =
	//apel get,set
	cout << "Greutate e2: " << e2.getGreutate() << endl;
	e2.setGreutate(10.2);
	cout << "Greutate e2: " << e2.getGreutate() << endl;

	Casnic c1;
	Casnic c2("Aspirator-proba 3", 1007, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 78.45, false, Culoare::pianoBlack, 300, "A+");
	Casnic c4(c2);//apel constructor de copiere
	c4 = c1; //apel operator =
	//apel get,set
	cout << "Clasa Energetica a lui c2 a fost: " << c2.getClasaEnergetica() << endl;
	c2.setClasaEnergetica("A+++");
	cout << "Clasa Energetica a lui c2 este: " << c2.getClasaEnergetica() << endl;

	Telefon t1;
	Telefon t2("Iphone 12", 2000, "Apple", "Best phone ever", 70100, 3, true, false, 0.712, true, Culoare::pianoBlack, 12.3, 1300, 4, true, "5G", "Hexa-core");
	Telefon t3(t1);
	t3 = t2;
	cout << "Procesorul telefonului este: " << t3.getProcesor() << endl;
	t3.setProcesor("Hexa Core");
	cout<< "Procesorul telefonului este: " << t3.getProcesor() << endl;

	Tv tv1;
	Tv tv2("Samsung OLED", 1234, "Samsung", "Super mega tv, negrul e negru", 64500, 10, true, true, 12.57, true, Culoare::roz, 13000, "A++", 41, "LCD", "1080x1920");
	Tv tv3(tv2);
	tv3 = tv1;
	cout << "Diagonala televizorului este: " << tv3.getDiagonala() << endl;
	tv3.setDiagonala(107);
	cout << "Diagonala televizorului este: " << tv3.getDiagonala() << endl;

	Frigider f1;
	Frigider f2("LG Door-in-Door", 1235, "LG", "Scump", 100000, 12, false, false, 89, true, Culoare::gri, 4900, "A+++", 4, 401, true);
	Frigider f3(f1);
	f3 = f2;
	cout << "Nr. usi: " << f2.getNrUsi() << endl;
	f2.setNrUsi(5);
	cout << "Nr. usi: " << f2.getNrUsi() << endl;

	User u2;
	vector<Produs> produseCumparate;
	produseCumparate.push_back(f2);
	produseCumparate.push_back(tv2);
	User u1("Cata Baro$$anu", "Top", "CataBoss99", produseCumparate);
	User u3(u1);
	u3 = u2;
	cout << "Numele utilizatorului este: " << u1.getNume()<< endl;
	u1.setNume("Catalean");
	cout << "Numele utilizatorului este: " << u1.getNume() << endl;

	Angajat a1;
	Angajat a2("Nedelcu", "Rebeca", "rbk@gmail.com", produseCumparate, 67000, "01.01.2021", "Manager");
	Angajat a3(a2);
	a3 = a1;
	cout << "Salariul angajatului este: " << a3.getSalariu() << endl;
	a3.setSalariu(45000);
	cout << "Salariul angajatului este: " << a3.getSalariu() << endl;





}
