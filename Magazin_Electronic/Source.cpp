#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Produs.h"
#include "Electronic.h"
#include "Telefon.h"
#include "Casnic.h"
#include "Tv.h"
#include "Frigider.h"
#include "User.h"
#include "Angajat.h"
#include "Controller.h"

using namespace std;


void main() {
	//Produs p1; //apel constructor implicit
	//Produs p2("Aspirator-proba", 1001, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false); //apel constructor cu parametri
	//Produs p3("Aspirator", 1002, "Rowenta", "Aspiratorul vietii tale", 1635, 2, true, false);
	//Produs p4(p2); //apel constructor de copiere
	//p4 = p3; //apel operator =
	////apel get,set
	//cout << "Pret p2 vechi: " << p2.getPret() << endl;
	//p2.setPret(69696);
	//cout << "Pret p2 nou: " << p2.getPret() << endl;

	//Electronic e1; //apel constructor implicit
	//Electronic e2("Aspirator-proba", 1005, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 7.2, false, Culoare::roz); //apel constructor cu parametri
	//Electronic e3("Aspirator-proba", 1006, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 7.45, false, Culoare::pianoBlack);
	//Electronic e4(e2);//apel constructor de copiere
	//e4 = e3; //apel operator =
	////apel get,set
	//cout << "Greutate e2: " << e2.getGreutate() << endl;
	//e2.setGreutate(10.2);
	//cout << "Greutate e2: " << e2.getGreutate() << endl;
	//cout << "Nume e2: " << e2.getNume() << endl;

	//Casnic c1;
	//Casnic c2("Aspirator-proba 3", 1007, "Rowenta", "Aspiratorul visurilor tale", 345, 0, true, false, 78.45, false, Culoare::pianoBlack, 300, "A+");
	//Casnic c4(c2);//apel constructor de copiere
	//c4 = c1; //apel operator =
	//apel get,set
	//cout << "Clasa Energetica a lui c2 a fost: " << c2.getClasaEnergetica() << endl;
	//c2.setClasaEnergetica("A+++");
	//cout << "Clasa Energetica a lui c2 este: " << c2.getClasaEnergetica() << endl;

	//Telefon t1;
	//Telefon t2("Iphone 12", 2000, "Apple", "Best phone ever", 70100, 3, true, false, 0.712, true, Culoare::pianoBlack, 12.3, 1300, 4, true, "5G", "Hexa-core1");
	//Telefon t3(t1);
	//t3 = t2;
	//cout << "Procesorul telefonului este: " << t3.getProcesor() << endl;
	//t3.setProcesor("Hexa Core");
	//cout<< "Procesorul telefonului este: " << t3.getProcesor() << endl;

	//Tv tv1;
	//Tv tv2("Samsung OLED", 1234, "Samsung", "Super mega tv, negrul e negru", 64500, 10, true, true, 12.57, true, Culoare::roz, 13000, "A++", 41, "LCD", "1080x1920");
	//Tv tv3(tv2);
	//tv3 = tv1;
	//cout << "Diagonala televizorului este: " << tv3.getDiagonala() << endl;
	//tv3.setDiagonala(107);
	//cout << "Diagonala televizorului este: " << tv3.getDiagonala() << endl;

	//Frigider f1;
	Frigider f2("LG Door-in-Door", 1235, "LG", "Scump", 100000, 12, false, false, 89, true, Culoare::gri, 4900, "A+++", 4, 401, true);
	//Frigider f3(f1);
	//f3 = f2;
	//cout << "Nr. usi: " << f2.getNrUsi() << endl;
	//f2.setNrUsi(5);
	//cout << "Nr. usi: " << f2.getNrUsi() << endl;

	//User u2;
	//vector<Produs> produseCumparate;
	//produseCumparate.push_back(f2);
	//produseCumparate.push_back(f1);
	//User u1("Cata Baro$$anu", "Top", "CataBoss99", produseCumparate);
	//User u3(u1);
	//u3 = u2;
	//cout << "Numele utilizatorului este: " << u1.getNume()<< endl;
	//u1.setNume("Catalean");
	//cout << "Numele utilizatorului este: " << u1.getNume() << endl;

	//vector<Produs> produseCumparate;

	//Angajat a1;
	//Angajat a2("Nedelcu", "Rebeca", "rbk@gmail.com", produseCumparate, 67000, "01.01.2021", "Manager");
	//Angajat a3(a2);
	////a3 = a1;
	//cout << "Salariul angajatului este: " << a3.getSalariu() << endl;
	//a3.setSalariu(45000);
	//cout << "Salariul angajatului este: " << a3.getSalariu() << endl;
	//cout << a3.getNume();

	Controller controller;
	controller.addProducts();
	//controller.getProducts();
	controller.deleteAllProducts();
	//controller.getProducts();
	controller.addProduct(f2.toString());
	controller.getProducts();

}
