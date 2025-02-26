#include <iostream>
#include <string>
using namespace std;

string shiperenc(string enter, string key) { // enter - Вводимое значение, key - ключ шифрования
	string encrypted; // Объявление переменной для записи готового шифра

	//int keyAmount; // Колличество повторений ключа
	string fullKey; // Ключ повторённый n-ное кол-во раз
	for (int i = 0; i < enter.length(); i++) {
		fullKey += key[i % key.length()];
	}
	// Проходим по каждому символу текста
	for (int i = 0; i < enter.length(); i++) {
		char charEnter = enter[i]; // символ из текста
		char charKey = key[i % key.length()];  //символ ключа 

		// Проверяем буква ли
		if (charEnter >= 'A' && charEnter <= 'Z') {
			//C(i) = (T(i) + K(i)) % 26
			char encrypted2 = 'A' + (charEnter - 'A' + charKey - 'A') % 26;
			encrypted += encrypted2; // Добавляем зашифрованный чар символ
		}
		else if (charEnter >= 'a' && charEnter <= 'z') {
			//C(i) = (T(i) + K(i)) % 26
			char encrypted2 = 'a' + (charEnter - 'a' + charKey - 'A') % 26;
			encrypted += encrypted2; // Добавляем зашифрованный чар символ
		}
		else {
			encrypted += charEnter; // Если символ не буква (например, пробел), оставляем без изменений
		}
	}

	return encrypted;



	//for (int i = 0; i < enter.size(); i++)
	//{
	 //encrypted[i] = (((enter[i] - 'a') + (key[i++ % key.size()] - 'a')) % 26) + 'a';
	 // Шифр цезаря c[i] = (p[i] + k) % 26  , где c - шифрованное слово, p - начальное, k - ключ
	//}
	//return encrypted;
}

string shiperdeenc(string enter, string key) {
	string encrypted; // Объявление переменной для записи готового шифра

	//int keyAmount; // Колличество повторений ключа
	string fullKey; // Ключ повторённый n-ное кол-во раз
	for (int i = 0; i < enter.length(); i++) {
		fullKey += key[i % key.length()];
	}
	// Проходим по каждому символу текста
	for (int i = 0; i < enter.length(); i++) {
		char charEnter = enter[i]; // символ из текста
		char charKey = key[i % key.length()];  //символ ключа 

		// Проверяем буква ли
		if (charEnter >= 'A' && charEnter <= 'Z') {
			//C(i) = (T(i) + K(i)) % 26
			char decrypted2 = 'A' + (charEnter - 'A' - (charKey - 'A') + 26) % 26;
			encrypted += decrypted2; // Добавляем зашифрованный чар символ
		}
		else if (charEnter >= 'a' && charEnter <= 'z') {
			//C(i) = (T(i) + K(i)) % 26
			char decrypted2 = 'a' + (charEnter - 'a' - (charKey - 'A') + 26) % 26;
			encrypted += decrypted2; // Добавляем зашифрованный чар символ
		}
		else {
			encrypted += charEnter; // Если символ не буква (например, пробел), оставляем без изменений
		}
	}

	return encrypted;
}

int main() {
	cout << shiperenc("ArBuZ", "SHI") << endl;
	cout << shiperdeenc("SyJmG", "SHI");

}