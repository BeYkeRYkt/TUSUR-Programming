/**
* The MIT License (MIT)
*
* Copyright (c) 2016 - 2020 D3v3l0p3d_0n3
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

void task8_11(){
	int N = 0;
	cout << "Введите N" << endl << "-> ";
	cin >> N;

	if (N < 0){
		cout << "Reverting! Число не может меньше нуля!";
		return;
	}

	int summ = 0;

	for (int i = 0; i <= N; i++){
		summ += pow(N + i, 2);
	}
	summ += pow(N * 2, 2);

	cout << "Результат: " << summ;
}

void task9_19(){
	int N = 0;
	cout << "Введите N" << endl << "-> ";
	cin >> N;


	int del = 0;
	cout << "Делим на " << endl << "-> ";
	cin >> del;

	if (del == 0){
		cout << "Reverting! На ноль делить нельзя!" << endl;
		return;
	}

	int div = N / del;
	int mod = N % del;

	cout << "Result: " << mod << " " << div;
}

void task10_13(){
	int summ = 0;

	bool run = true;

	cout << "Введите числа" << endl << "-> ";
	while (run){
		int N = 0;
		cin >> N;
		if (N == 0){
			break; //Break down!
		} else if (N > 0){
			summ += N;
		}
	}
	cout << "Результат суммы: " << summ;
}

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	bool run = true;

	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера -->" << endl;
		cout << "11,  19,  13";
		cout << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 11:
			task8_11();
			break;
		case 19:
			task9_19();
			break;
		case 13:
			task10_13();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}