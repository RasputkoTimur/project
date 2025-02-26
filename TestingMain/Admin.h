#pragma once
#include "User.h"
#include "Question.h"
#include<string>
using namespace std;
#include <iostream>
#include <fstream>

class Admin : public User
{
public:
    Admin();
    void changePassword();
    void changeLogin();
    void addUser();
    void delUser();
    void changeUser(int);
    void watchStatistic();
    void addCategory(string);
    void addQuestion(Question);
    void importTest();
    void exportTest();
    void importCategory();
    void exportCategory();
    ~Admin();

};

