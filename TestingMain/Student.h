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
	~Student();
};

