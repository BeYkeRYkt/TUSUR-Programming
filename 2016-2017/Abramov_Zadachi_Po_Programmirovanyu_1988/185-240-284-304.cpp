/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>
#include <cmath>

using namespace std;

int count_numbers(int n){
	int k = 1;
	while (n /= 10) ++k;
	return k;
}

void task185(){
	int N = 0;
	double a = 0;
	cout << "Введите N" << endl << "-> ";
	cin >> N;

	cout << "Введите A(n)" << endl << "-> ";
	double result = 0;

	for (int i = 0; i < N; i++){
		double value = 0;
		cin >> value;
		if (value > 0){
			result += value;
		}
	}
	cout << "Результат: " << result * 2;
}

void task240(){
	int number;
	cout << "Введите N" << endl << "-> ";
	cin >> number;

	int code = 0;
	cout << "Введите цифру (А - 0, Б - 1): " << endl << "-> ";
	cin >> code;

	double sum = 0;

	// #1
	if (code == 0){
		for (int i = 1; i <= number; i++)
		{
			sum += count_numbers(i) / pow((double)i, 2);
		}
	}
	// #2
	else if (code == 1){
		cout << "Введите действительное число X: " << endl << "-> ";
		double x;
		cin >> x;

		for (int i = 1; i <= number; i++)
		{
			sum += pow((double)10, count_numbers(i)) / (i * pow(double(1 - x), 2));
		}
	}
	else{
		cout << "ERROR!";
		return;
	}
	cout << "Результат (№2): " << sum;
}

void task284(){
	//TODO: Need implement b)
	int N = 20;
	int *arr = new int[];

	cout << "Введите " << N << " чисел" << endl << "-> ";
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for (int i = 1; i < N; i += 2){
		cout << arr[i] << " ";
	}

	for (int i = 0; i < N; i += 2){
		cout << arr[i] << " ";
	}
}

void task304(){
	const int n = 16;

	double mas[n];
	int tmp = 0;
	cout << "Введите вводные данные (16 чисел): " << endl << "-> ";
	for (int i = 0; i < n; i++){
		double value = 0;
		cin >> value;
		mas[i] = value;
		cout << mas[i] << " ";
	}
	double mastmp[n];
	for (int i = 0; i < n; i++){
		if (mas[i] > 0){
			mastmp[tmp] = mas[i];
			tmp++;
		}
	}
	for (int i = 0; i < n; i++){
		if (mas[i] < 0 || mas[i] == 0){
			mastmp[tmp] = mas[i];
			tmp++;
		}
	}
	cout << endl << "Результат: ";
	for (int i = 0; i < n; i++)
		cout << mastmp[i] << " ";
}

int main(){
	setlocale(LC_ALL, "Russian");
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 185 << " " << 240 << " " << 284 << " " << 304 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 185:
			task185();
			break;
		case 240:
			task240();
			break;
		case 284:
			task284();
			break;
		case 304:
			task304();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}