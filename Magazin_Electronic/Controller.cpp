#include "Controller.h"
#include <iostream>
#include <string>
#include "Telefon.h"
#include <iterator>

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


//void Controller::addProduct(string product) {
//	ofstream out;
//	out.open("products.bin", ios::out | ios::binary | ios_base::app);
//	out << product << endl;
//	out.close();
//}

void Controller::addProduct(Produs* product) {
	ofstream out("test.bin", ios::binary | ios_base::app);
	out.write((char*)product, sizeof(product));
	out.close();
}

void Controller::readProduct() {
	ifstream f("test.bin", ios::binary);
	if (f.is_open()) {
		f.seekg(0, ios::beg);

		Produs* aux;
		while (!f.eof())
		{
			f.read((char*)&aux, sizeof(Produs*));
			cout << aux->getNume();
		}
		cout << endl;
		f.close();
	}
	else
		cerr << "Eroare la deschiderea Produs.dat pentru citire";
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

void Controller::sendOrder(User u) {
	ofstream out;
	int size;
	size = u.prepareOrder().size();

	out.open("comenzi.bin", ios::binary | ios::app);
	out.write((char*)&size, sizeof(int));
	out.write((char*)&u.prepareOrder()[0], size);
	out.close();

	out.open("comanda" + u.getNume() + u.getPrenume()+".txt", ios::app);
	out.write((char*)&size, sizeof(int));
	out.write((char*)&u.prepareOrder()[0], size);
	cout << "Detalii comanda trimise la " + u.getEmail() << endl;
	out.close();
}

void Controller::viewOrders(bool print) {
	ifstream infile("comenzi.bin", ifstream::binary);
	float size;
	string s;
	if (infile.is_open()) {
		infile.read(reinterpret_cast<char*>(&size), sizeof(size));
		s.resize(9999);
		s[size] = '\0';
		infile.read(&s[0], s.size());
		if (!print) {
			cout << s;
		};
		if (print) {
			printOrders(s);
		}
		infile.close();
	}
	else
		cerr << "Eroare la deschiderea Produs.dat pentru citire";
}

void Controller::printOrders(string s) {
	ofstream out;
	int size;
	size = s.size();

	out.open("comenzi.txt", ios::out);
	out.write((char*)&size, sizeof(int));
	out.write((char*)&s[0], size);
	cout << "\nFisierul comenzi.txt a fost creat!\n";
}


