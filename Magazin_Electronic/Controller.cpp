#include "Controller.h"
#include <iostream>
#include <string>
#include "Telefon.h"

using namespace std;

int Controller::chooseInput(int start, int finish) {
	int input;
	bool wrongInput = false;
	do {
		if (wrongInput) {
			cout << "\nWrong input!" << endl;
		}
		cout << "\nChoose an option: ";
		cin >> input;
		wrongInput = true;
	} while (input < start || input > finish);

	return input;
}

string Controller::addStringInfo(string s) {
	cout << endl << s;
	string input;
	cin >> input;
	return input;
}

void Controller::getProducts() {
	ifstream in;
	string item;
	in.open("products.bin", ios::in | ios::binary);
	if (in.fail()) {
		cout << "failed to get products";
		exit(1);
	}
	while (getline(in, item)) {
		cout << item << endl;
	}
	in.close();
}


void Controller::addProduct(string product) {
	ofstream out;
	out.open("products.bin", ios::out | ios::binary | ios_base::app);
	out << product << endl;
	out.close();
}


void Controller::addProductToShop(vector<Produs*>& produseDisponibile, Produs* const& produs) {
	produs->setAttributes();
	produseDisponibile.push_back(produs);
	this->saveProduct(produs);
}


void Controller::saveProduct(Produs* produs) {
	ofstream out;
	out.open("products.bin", ios::out | ios::binary | ios_base::app);

	out << produs->toString() << endl;
	
	out.close();
}

void Controller::deleteProductFromShop(vector<Produs*>& produseDisponibile, int index) {
	produseDisponibile[index - 1] = produseDisponibile.back();
	produseDisponibile.pop_back();
}

void Controller::editProductFromShop(vector<Produs*>& produseDisponibile, int index) {
	produseDisponibile[index - 1]->setAttributes();
}
	

void Controller::deleteAllProducts() {
	ofstream out;
	out.open("products.bin");
	out << "";
	out.close();
}


