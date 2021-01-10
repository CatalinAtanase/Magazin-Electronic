#pragma once
#include <vector>
#include "Produs.h"

using namespace std;

class View {
public:
	void login();
	void menu(int userType);
	void showProductsToAdd();
	void showAllProducts(vector<Produs*> produse);
	void addProductToCart();
};

