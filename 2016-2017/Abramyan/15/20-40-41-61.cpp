/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

/*
* String (15)
*/

void task20(){
	int c, i = 0;
	cout << "Введите число" << endl << "-> ";
	cin >> c;

	short arr[10];
	while (c)
	{
		arr[i] = c % 10;
		c /= 10;
		i++;
	}

	while (--i >= 0){
		cout << arr[i] << " ";
	}

}

void task40(){
	string text;
	cout << "Введите текст" << endl << "-> ";
	cin.get(); //fix
	getline(cin, text);
	int l = text.find_first_of(" ");
	int r = text.find_last_of(" ");
	if (l == r){
		cout << '\n';
	}
	else {
		cout << text.substr(l + 1, r - l - 1) << endl;
	}
}

void task41(){
	string text;
	cout << "Введите текст" << endl << "-> ";
	cin.get(); //fix
	getline(cin, text);

	const char *psz = text.c_str();
	int count = 0;
	if (strcmp("", psz) < 0) count++;
	for (int i = 0; (psz[i] != '\0') && (i < strlen(psz) - 1); i++){
		if (isspace(psz[i]) && isalnum(psz[i + 1])){
			count++;
		}
	}

	cout << "Количество слов: " << count << endl;
}

void task61(){
	char path[80], dirname[80];
	int  beg, end, i;

	cout << "Введите текст" << endl << "-> ";
	cin.get(); //fix
	cin.getline(path, 80);
	i = strlen(path);


	while (path[i] != '\\' && i >= 0){
		i--;
	}

	if (i > 0){
		end = i + 1;
	}

	i--;
	while (path[i] != '\\' && i >= 0){
		i--;
	}

	if (i < 0){
		cout << '\\' << endl;
	}
	else {
		beg = i + 1;
		strncpy(dirname, path + beg, end - beg - 1);
		dirname[end - beg - 1] = '\0';
		cout << dirname << endl;
	}
}

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	bool run = true;
	// 20 40 41 61
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера -->" << endl;
		cout << "20 40 41 61";
		cout << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 20:
			task20();
			break;
		case 40:
			task40();
			break;
		case 41:
			task41();
			break;
		case 61:
			task61();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}
