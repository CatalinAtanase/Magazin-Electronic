#include "Controller.h"
#include <iostream>
#include <string>

using namespace std;

// de facut un vector cu produse
// cand stergi cv rescriem tot fisierul
// ez clap
void Controller::addProducts() {
	ofstream out;
	out.open("products.bin", ios::out | ios::binary | ios_base::app);
	out << "My first product" << endl;
	out << "some text\nsometetx2\nsometext3" << endl;
	out.close();
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

void Controller::deleteAllProducts() {
	ofstream out;
	out.open("products.bin");
	out << "";
	out.close();
}

void Controller::addProduct(string product) {
	ofstream out;
	out.open("products.bin", ios::out | ios::binary | ios_base::app);
	out << product << endl;
	out.close();
}
