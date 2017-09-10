#include <string.h>
#include <fstream>
#include <iostream> 
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

fstream stream;

bool load(){
	if (stream.is_open()){
		stream.close();
	}
	stream.open("dict.txt");
	if (!stream.good()){
		cout << "Error while reading file." << endl;
		return false;
	}
	return true;
}

vector<string> splitTran(string word){
	vector<string> commands;
	string buffer = ""; 
	for (int i = 0; i <= word.size(); i++){
		if (word[i] == ',' || word[i] == ' ' || i == word.size()){
			commands.push_back(buffer);
			buffer = "";
		}else{
			buffer += word[i];
		}
	}
	return commands;
}

void engToRu(){
	string word;
	cout << "Введите слово: " << endl << "-> ";
	cin >> word;

	if (!load()){
		return;
	}

	string delimiter = "=";
	bool found = false;
	string buff = "NULL";
	while (stream >> buff){
		string token = buff.substr(0, buff.find(delimiter));
		if (!token.find(word) || token == word){
			found = true;
			string translate = buff.substr(buff.find(delimiter) + 1, buff.size());
			cout << "Возможные переводы: " << endl;
			vector<string> vec = splitTran(translate);
			for (int i = 0; i < vec.size(); i++){
				cout << "- " << vec[i] << endl;
			}
			break;
		}
	}
	if (!found){
		cout << "Перевод не найден" << endl;
	}
	stream.close();
	cout << endl;
}

void ruToEng(){
	string word;
	cout << "Введите слово: " << endl << "-> ";
	cin >> word;

	if (!load()){
		return;
	}

	string delimiter = "=";
	bool found = false;
	string buff = "NULL";
	cout << "Возможные переводы: " << endl;
	while (stream >> buff){
		string token = buff.substr(buff.find(delimiter) + 1, buff.size());

		vector<string> vec = splitTran(token);
		for (int i = 0; i < vec.size(); i++){
			if (!vec[i].find(word) || vec[i] == word){
				found = true;
				string translate = buff.substr(0, buff.find(delimiter));
				cout << "- " << translate << endl;
				//break;
			}
		}
	}
	if (!found){
		cout << "Перевод не найден" << endl;
	}
	stream.close();
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool run = true;
	while (run){
		cout << "Введите код: " << endl;
		cout << "0. Выход" << endl;
		cout << "1. Перевод с английского на русский" << endl;
		cout << "2. Перевод с русского на английский" << endl;
		cout << "-> ";
		int code = 0;
		cin >> code;
		switch (code){
		case 0:
			run = false;
			break;
		case 1: // En-Ru
			engToRu();
			break;
		case 2: // Ru-Eng
			ruToEng();
			break;
		}
	}
}