#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
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
        while (getline(in, line, ':')) {
            string loginFile;
            if (loginFile.compare(login)) {
            
            }
            if (loginFile == login) {
                loginFlag = true;
            }
            getline(in, line);
        }
        if (loginFlag == false) {
            cout << "incorrect login!";
            continue;
        }
        cout << "Enter your password: ";
        cin >> password;
        while (getline(in, line, ':')) {
            string passwordFile;
            int index = 0;
            for (int i = 0; line[i] != '\0'; i++) {
                if (line[i] == ':') {
                    index = i + 1;
                    break;

                }
            }
            for (int i = index; line[i] != '\0'; i++) {
                passwordFile += line[i];
            }
            if (passwordFile == password) {
                passwordFlag = true;
            }
        }
        if (passwordFlag == false) {
            cout << "incorrect password!";
            continue;
        }
        else {
            cout << "You entered system succesfully!";
            break;
        }
    }
    
}
