#include "Admin.h"

void Admin::changePassword()
{
	cout << "Enter your new password: ";
	cin >> this->password;
}

void Admin::changeLogin()
{
	cout << "Enter your new login: ";
	cin >> this->login;
}

void Admin::addUser()
{
	string line;
	string loginFile;
	cout << "Enter User login you want to add: ";
	cin >> loginFile;
	ofstream out("admins.txt");
	ifstream in("users.txt");
	bool flag = false;
	while (getline(in, line, ':')) {
		if (line == loginFile) {
			out << line;
			getline(in, line);
			out << ":" << line;
			flag = true;
			break;
		}
		else {
			getline(in, line);
		}
	}
	if (flag == true) cout << "User is added to admins" << endl;
	else if (flag == false) cout << "There is no user with this login" << endl;
	out.close();
	in.close();
}

void Admin::delUser()
{
	string line;
	string loginFile;
	cout << "Enter login of user you want to delete: ";
	cin >> loginFile;
	ofstream out("newUsers.txt");
	ifstream in("users.txt");
	while (getline(in, line, ':')) {
		if (loginFile != line) {
			out << line;
			getline(in, line);
			out << ":" << line;
		}
		else {
			getline(in, line);
		}
	}
	in.close();
	out.close();
	ofstream out2("users.txt");
	ifstream in2("newUsers.txt");
	while (getline(in2, line)) {
		out2 << line;
	}
	in.close();
	out.close();
}

void Admin::changeUser(int)
{
}
