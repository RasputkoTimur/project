#include "Student.h"

void Student::login()
{
    while (true) {
        string login;
        string password;
        ifstream in("users.txt");
        string line;
        bool loginFlag = false;
        bool passwordFlag = false;
        cout << "Enter your login: ";
        cin >> login;
        cout << "Enter your password: ";
        cin >> password;
        while (getline(in, line, ':')) {
            if (login.compare(line) == 0) {
                loginFlag = true;
            }
            getline(in, line);
            if (password.compare(line) == 0) {
                passwordFlag = true;
            }
        }
        if (loginFlag == false || passwordFlag == false) {
            cout << "incorrect login or password!" << endl;
            continue;
        }
        else {
            cout << "You entered system succesfully!" << endl;
            break;
        }
    }
}
