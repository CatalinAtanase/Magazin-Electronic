#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Produs.h"
#include "IUser.h"


class User : public IUser{
protected:
	string nume;
	string prenume;
	string email;
	vector<Produs *> cos;

	//constructori implicit
public:
	User();
	User(string nume, string prenume, string email, vector<Produs *> cos);
	~User();
	User(User& u);
	void operator=(User u);
	string getEmail();
	string getNume();
	string getPrenume();
	int getCartSize();
	void setEmail(string email);
	void setNume(string nume);
	void setPrenume(string nume);
	void greeting();
	void addToCart(Produs* produs);
	void showCart();
	void deleteItemFromCart(vector<Produs*> &produseMagazin, int index);
	string prepareOrder();
};

