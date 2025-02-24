#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class User
{
	string name, lastName, password, login, phone, adress;
public:
	User();
	void registration();
	~User();

};

