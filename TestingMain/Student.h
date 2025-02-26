#pragma once
#include "User.h"
class Student :
	protected User
{
public:
	Student();
	void login();
	void watchPrevTests();
	void completeTest();
	string getrName();
	string getrLastName();
	string getrPassword();
	string getrLogin();
	string getrPhone();
	string getrAdress();
	~Student();
};
