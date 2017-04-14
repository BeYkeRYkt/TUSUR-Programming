/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void task374v(){
	int N = 0;
	cout << "Введите N: " << endl << "-> ";
	cin >> N;
	int result = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (sin(((i * i) + (j * j)) / 2) > 0){
				result++;
			}
		}
	}

	cout << "Результат: " << endl << "-> " << result;
}

void task378b(){
	const int N = 8;
	double x[N];
	for (int i = 0; i < 8; i++){
		cout << "Введите x" << i << " : ";
		cin >> x[i];
	}

	double a[N][N];
	int i, j = 0;

	for (i = 0; i < N; i++) {
		a[0][i] = 1;
	}
	for (i = 1; i < N; ++i){
		for (j = 0; j < N; ++j){
			int value = x[j];
			for (int k = 0; k < i - 1; k++){
				value *= x[j];
			}
			a[i][j] = value;
		}
	}

	cout << "Результат: " << endl;
	for (i = 0; i < N; ++i){
		for (j = 0; j < N; ++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void task393g(){
	const int N = 3;
	double x[N][N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << "Введите x" << i << "-" << j << " : ";
			cin >> x[i][j];
		}
	}

	for (int i = 0; i < N; i++){
		int bi = 0;
		for (int j = 0; j < N; j++){
			if (x[i][j] > 0){
				bi += x[i][j];
			}
		}
		if (bi <= 0){
			bi = -1;
		}
		cout << "b" << i << "=" << bi << endl;
	}
}

void task410b(){
	srand(time(NULL));
	const int N = 6;
	double arr[N][N];

	//Put array
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			double d = (double)(rand() % 100);
			arr[i][j] = d;
		}
	}

	cout << "Исходная матрица" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++){
		int bi = 0;
		for (int j = 0; j < N; j++){
			bi += arr[i][j] * ((i + j) % 2 == 0 ? 1 : -1);
		}
		cout << "b[" << i << "]=" << bi << endl;
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 374 << " " << 378 << " " << 393 << " " << 410 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 374:
			task374v();
			break;
		case 378:
			task378b();
			break;
		case 393:
			task393g();
			break;
		case 410:
			task410b();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}