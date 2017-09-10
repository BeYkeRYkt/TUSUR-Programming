/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>

using namespace std;


void task84(){
	int N = 0;
	double x = 0;
	cout << "Введите N" << endl << "-> ";
	cin >> N;

	cout << "Введите X" << endl << "-> ";
	cin >> x;

	double result = 0;

	for (int i = 0; i < N; i++){
		double sinr = 1;
		for (int j = 0; j < i; j++){
			sinr *= sin(x);
		}
		result += sinr;
	}
	cout << "Результат: " << result;
}

void task103(){
	double e;

	cout << "Введите E" << endl << "-> ";
	cin >> e;
	double previos = 0;
	double next = 1;
	while ((next - previos)>=e){
		previos = next;
		next = (previos + 1) / (previos + 2);
	}
	cout << "Результат: " << next;
}

void task145(){
	cout << "Получение результатов из последовательности: " << endl;

	cout.precision(17);
	double *a = new double[40];
	cout << "x1= " << 0 << endl;
	cout << "x2= " << (double)5 / 8 << endl;
	a[0] = 0;
	a[1] = (double) 5 / 8;
	for (int i = 2; i < 40; i++){
		//double xi = x(i);
		double ai = (a[i - 1] / 2) + ((3 / 4) * a[i - 2]);
		a[i] = ai;
		cout << "x" << fixed << i << "= " << ai << endl;
	}
}

void task165(){
	cout << "Введите первое число большее нуля: " << endl << "-> ";
	bool run = true;
	double result = 0;
	cin >> result;

	cout << "Введите числа: " << endl << "-> ";

	while (run){
		int s = 0;
		cin >> s;
		if (s > 0){
			result *= s;
		}
		else {
			run = false;
		}
	}

	cout << "Результат: " << result;
}
 
// 165
int main(){
	setlocale(LC_ALL, "Russian");
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 84 << " " << 103 << " " << 145 << " " << 165 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 84:
			task84();
			break;
		case 103:
			task103();
			break;
		case 145:
			task145();
			break;
		case 165:
			task165();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}