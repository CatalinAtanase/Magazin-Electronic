#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Controller {
public:
	void addProducts();
	void getProducts();
	void deleteAllProducts();
	void addProduct(string product);
};

