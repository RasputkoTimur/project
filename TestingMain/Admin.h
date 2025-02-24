#pragma once
#include "User.h"
#include "Question.h"
#include<string>
using namespace std;
class Admin :
    protected User
{
    public:
        Admin();
        void changePassword();
        void changeLogin();
        void addUser(User);
        void delUser(int);
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

