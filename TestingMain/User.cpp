#include "User.h"

void User::registration()
{
  string login; string buf;
  string password;
  cout << "enter your login and then the password on the new line:" << endl;
  cin >> login;
  cin >> password;
  
  fstream file("login_And_Pasword.txt");
  while (getline(file, buf, ':')) {
  	if (buf == login) {
  		cout << "the login is already occupied, choose another one: " << endl;
  		cin >> login;
  		registration();
  	}
  	else{
  		// login = функция шифрования 
  		// password = функция шифрования 
  		file << login << ':' << password;}
  	
  }
  
  file.close();
}
