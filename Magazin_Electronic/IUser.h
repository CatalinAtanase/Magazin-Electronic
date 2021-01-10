#pragma once
#include <string>
#include <iostream>

using namespace std;

class IUser {
public:
	string nume;
	string prenume;
	virtual void greeting();
};

