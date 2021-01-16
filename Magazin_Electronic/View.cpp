#include "View.h"
#include <iostream>

using namespace std;

void View::login() {
	cout << "*** WELCOME ***" << endl;
	cout << "Login as:\n";
	cout << "  1. Admin\n";
	cout << "  2. User\n";
}


void View::menu(int userType) {
	// userType = 1 for admin, 2 for user
	if (userType == 1) {
		cout << "\nCe actiune doriti sa realizati?\n";
		cout << "1. Afiseaza produse\n";
		cout << "2. Adauga produs in magazin\n";
		cout << "3. Sterge produs din magazin\n";
		cout << "4. Editeaza produse din magazin\n";
		cout << "5. Afiseaza comenzi\n";
		cout << "6. Raport comenzi\n";
		cout << "0. Exit\n";
	}
	else {
		cout << "\nCe actiune doriti sa realizati?\n";
		cout << "1. Afiseaza produse\n";
		cout << "2. Adauga produs in cos\n";
		cout << "3. Afiseaza produse din cos\n";
		cout << "4. Sterge produs din cos\n";
		cout << "5. Trimite comanda\n";
		cout << "0. Exit\n";
	}
	cout << "";
}

void View::showProductsToAdd() {
	cout << endl << "Ce tip de produs doriti sa adaugati?\n";
	cout << "1. Telefon\n";
	cout << "2. Televizor\n";
	cout << "3. Frigider\n";
}

void View::showAllProducts(vector<Produs *> produse) {
	vector<Produs*>::iterator it;
	cout << "\nAfisare produse disponibile." << endl;
	int counter = 1;

	if (produse.size()) {
		for (it = produse.begin(); it != produse.end(); it++) {
			cout << counter << ". " << (*it)->toString() << endl;
			counter++;
		}
	}
	else {
		cout << "\nNu sunt produse disponibile momentan\n";
	}

	
}

void View::addProductToCart() {
	cout << "\nIntroduceti numarul produsului din magazin: ";

}