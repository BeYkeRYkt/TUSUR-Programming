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
#include <fstream>

using namespace std;

/*
* Нахождение минимального элемента в массиве
* A - массив, N - размер
*/
double *getMin(double *A, int N){
	double *m = A;
	for (int i = 0; i < N; i++){
		if (A[i] < *m){
			m = A + i;
		}
	}
	return m;
}

/*
* Extrime Hill Climb Racing
* A - массив, N - размер
*/
void Hill(double *A, int N){
	double *a = new double[N]; // workbench for experiments
	for (int i = 0; i < N; ++i){
		a[i] = A[i]; //copy to workbench array
	}
	for (int i = 0; i < N; ++i){// Sorting 0 > 1
		double t = a[i];
		double *m = getMin(a + i, N - i);
		a[i] = *m;
		*m = t;
	}
	//Magic tricks ?
	for (int i = 0; i < N; ++i){
		if (i % 2){
			A[N - (i / 2 + 1)] = a[i];
		}
		else{
			A[i / 2] = a[i];
		}
	}
	delete a;
}

void task13(){
	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
	unsigned na = sizeof(a) / sizeof(*a);

	double b[] = { 9.9, 8.8, 7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1 };
	unsigned nb = sizeof(b) / sizeof(*b);

	double c[] = { 1, 9, 2, 8, 3, 7, 4, 6, 5 };
	unsigned nc = sizeof(c) / sizeof(*c);

	//Before...
	//get A
	cout << "Original: " << endl;
	cout << "A= ";
	for (int i = 0; i < na; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	//get B
	cout << "B= ";
	for (int i = 0; i < nb; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	//get C
	cout << "C= ";
	for (int i = 0; i < nc; ++i) {
		cout << c[i] << " ";
	}
	cout << endl;

	//Processing...
	Hill(a, na);
	Hill(b, nb);
	Hill(c, nc);

	//After...
	cout << endl << "Modded: " << endl;
	//get A
	cout << "A= ";
	for (int i = 0; i < na; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	//get B
	cout << "B= ";
	for (int i = 0; i < nb; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;

	//get C
	cout << "C= ";
	for (int i = 0; i < nc; ++i) {
		cout << c[i] << " ";
	}
	cout << endl;
}

string fillStr(string s, int N){
	int i = 0;
	string stemp = "";

	while (stemp.length() < N){
		stemp = stemp + s;
	}
	return stemp.substr(0, N);
}

void task31(){
	int N = 0;
	cout << "Введите N" << endl << "-> ";
	cin.get(); //fix
	cin >> N;

	for (int i = 0; i < 5; i++){
		string text;
		cout << "Введите текст" << endl << "-> ";
		cin.get(); //fix
		getline(cin, text);
		cout << fillStr(text, N) << endl;
	}
}

void SplitText(string s0, int k, string s1, string s2){
	//write s1
	fstream inputFile(s0);
	if (!inputFile.is_open()){
		cout << "error";
		return;
	}

	fstream inputFileS1(s1, ofstream::out | ofstream::trunc);
	for (int i = 0; i < k; i++){
		int length = 50;
		char* input_buffer = new char[length + 1]();
		inputFile.getline(input_buffer, length);

		//Getting last index
		int lastIndex = 0;
		while (input_buffer[lastIndex] != NULL){
			lastIndex++;
		}

		input_buffer[lastIndex] = '\n';
		cout << input_buffer;
		//write(s1, input_buffer);

		//write - start
		if (!inputFileS1.is_open()){
			cout << "I can't write this file!";
			return;
		}
		inputFileS1 << input_buffer;
		//write - end

		delete input_buffer;
	}

	//write s2
	fstream inputFileS2(s2, ofstream::out | ofstream::trunc);
	if (!inputFileS2.is_open()){
		cout << "I can't write this file!";
		return;
	}

	int length = 50;
	char* input_buffer2 = new char[length + 1]();
	while (inputFile.getline(input_buffer2, length)){
		//Getting last index
		int lastIndex = 0;
		while (input_buffer2[lastIndex] != NULL){
			lastIndex++;
		}

		input_buffer2[lastIndex] = '\n';
		cout << input_buffer2;
		//write(s2, input_buffer2);
		inputFileS2 << input_buffer2;
	}

	delete input_buffer2;
	inputFileS2.close();
	inputFile.close();
}

void task54(){
	string s0 = "s0.txt";
	int K = 0;
	string s1 = "s1.txt";
	string s2 = "s2.txt";

	cout << "Введите k" << endl << "-> ";
	cin >> K;
	SplitText(s0, K, s1, s2);
}

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	bool run = true;
	// 13 31 54
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера -->" << endl;
		cout << "13 31 54";
		cout << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 13:
			task13();
			break;
		case 31:
			task31();
			break;
		case 54:
			task54();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}