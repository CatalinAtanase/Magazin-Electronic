#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Produs.h"
#include <vector>

using namespace std;

class Controller {
public:
	void saveProduct(Produs* produs);
	void getProducts();
	void deleteAllProducts();
	void addProduct(string product);
	int chooseInput(int start, int finish);
	string addStringInfo(string s);
	void addProductToShop(vector<Produs *> &produseDisponibile, Produs* const &produs);
};

