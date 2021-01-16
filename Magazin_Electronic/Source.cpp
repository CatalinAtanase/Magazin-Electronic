#include <iostream>
#include <string>
#include <vector>
#include <list>
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
#include "View.h"

using namespace std;


void main() {
	Controller controller;
	View view;
	int input;

	//Telefon telefon("Iphone 12", 2000, "Apple", "Best phone ever", 70100, 3, true, false, 0.712, true, Culoare::pianoBlack, 12.3, 1300, 4, true, "5G", "Hexa-core1");
	Frigider frigider("LG Door-in-Door", 1235, "LG", "Scump", 100000, 12, false, false, 89, true, Culoare::gri, 4900, "A+++", 4, 401, true);
	Telefon telefon("Telefon", 1000, "Apple", "Descriere", 3000, 1, true, true, 2, true, Culoare::gri, 12.2, 3000, 3, true, "Vodafoe", "Procesor");
	Tv tv("Samsung OLED", 1234, "Samsung", "Super mega tv, negrul e negru", 64500, 10, true, true, 12.57, true, Culoare::roz, 13000, "A++", 41, "LCD", "1080x1920");

	//controller.deleteAllProducts();

	vector<Produs *> produseDisponibile;

	produseDisponibile.push_back(&telefon);
	produseDisponibile.push_back(&frigider);
	produseDisponibile.push_back(&tv);

	controller.addProduct(&telefon);
	controller.addProduct(&frigider);
	controller.addProduct(&tv);


	view.login();
	input = controller.chooseInput(1, 2);

	if (input == 1) {
		cout << endl << "Te-ai autentificat ca angajat! Este timpul sa iti modifici profilul." << endl;
		Angajat angajat;
		angajat.setDataAngajare("01-01-2021");
		angajat.setSalariu(3000);
		angajat.setPrenume(controller.addStringInfo("Prenumele dvs: "));
		angajat.setNume(controller.addStringInfo("Numele dvs: "));
		angajat.setEmail(controller.addStringInfo("Emailul dvs: "));
		angajat.greeting();
		
		while (input != 0) {
			view.menu(1);
			input = controller.chooseInput(0, 6);
			if (input == 1) {
				view.showAllProducts(produseDisponibile);
			}
			else if (input == 2) {
				view.showProductsToAdd();
				input = controller.chooseInput(1, 3);
				switch (input)
				{
				case 1:
					controller.addProductToShop(produseDisponibile, &telefon);
					break;
				case 2:
					controller.addProductToShop(produseDisponibile, &tv);
					break;
				case 3:
					controller.addProductToShop(produseDisponibile, &frigider);
					break;
				default:
					break;
				}
			}
			else if (input == 3) {
				view.showAllProducts(produseDisponibile);
				cout << "\nCe produs doriti sa stergeti?\n";
				if (produseDisponibile.size()) {
					input = controller.chooseInput(1, produseDisponibile.size());
					controller.deleteProductFromShop(produseDisponibile, input);
				}
			}
			else if (input == 4) {
				view.showAllProducts(produseDisponibile);
				cout << "\nCe produs doriti sa editati?\n";
				input = controller.chooseInput(1, produseDisponibile.size());
				controller.editProductFromShop(produseDisponibile, input);
			}
			else if (input == 5) {
				controller.viewOrders(false);
			}
			else if (input == 6) {
				controller.viewOrders(true);
			}
		}
	}
	else {
		cout << endl << "Te-ai autentificat ca utilizator! Este timpul sa iti creezi profilul." << endl;
		User user;
		user.setPrenume(controller.addStringInfo("Prenumele dvs: "));
		user.setNume(controller.addStringInfo("Numele dvs: "));
		user.setEmail(controller.addStringInfo("Emailul dvs: "));
		user.greeting();

		while (input != 0) {
			view.menu(2);
			input = controller.chooseInput(0, 5);
			if (input == 1) {
				view.showAllProducts(produseDisponibile);
			}
			else if (input == 2) {
				if (produseDisponibile.size()) {
					view.addProductToCart();
					input = controller.chooseInput(1, produseDisponibile.size());
					user.addToCart(produseDisponibile[input - 1]);
					produseDisponibile[input-1] = produseDisponibile.back();
					produseDisponibile.pop_back();
				}
				else {
					cout << "\nNu sunt produse disponibile in magazin.\n";
				}

			}
			else if (input == 3) {
				user.showCart();
			}
			else if (input == 4) {
				user.showCart();
				cout << "\nCe produs doriti sa stergeti? ";
				input = controller.chooseInput(1, user.getCartSize());
				user.deleteItemFromCart(produseDisponibile, input);
			}
			else if (input == 5) {
				if (user.getCartSize()) {
					controller.sendOrder(user);
				}
				else {
					cout << "Nu aveti produse in cos!\n";
				}
			}
		}
	}

}

