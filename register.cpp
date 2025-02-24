#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string login;
	string password;
	string name;
	string lastName;
	string adress;
	string phoneNumber;
	cout << "Enter your login: ";
	cin >> login;
	while (true) {
		bool flagSmallLet = false;
		bool flagBigLet = false;
		bool flagNum = false;
		bool flagLength = false;
		bool flagSpecial = false;
		cout << "Enter your password: ";
		cin >> password;
		for (int i = 0; password[i] != '\0'; i++) {
			if (password[i] >= 65 && password[i] <= 90) {
				flagBigLet = true;
			}
			else if (password[i] >= 97 && password[i] <= 122) {
				flagSmallLet = true;
			}
			else if (password[i] >= 48 && password[i] <= 57) {
				flagNum = true;
			}
			else flagSpecial = true;
		}
		if (password.length() >= 8 && password.length() <= 14) flagLength = true;
		if (flagLength == true && flagBigLet == true && flagSmallLet == true && flagNum == true && flagSpecial == true) {
			break;
		}
		else {
			cout << "Password length must be from 8 to 14, it also must have special element, big and small letter and a number" 
				<< endl;
		}
	}
	
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your adress: ";
	cin >> adress;
	cout << "Enter your phone number: ";
	cin >> phoneNumber;
	ofstream out("users.txt");
	out << login << ":" << password;
	out.close();

}