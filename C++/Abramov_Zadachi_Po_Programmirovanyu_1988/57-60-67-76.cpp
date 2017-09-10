/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void task60(){
	double x = 0;
	double y = 0;
	int code = 0;
	double u;

	cout << "Введите X" << endl << "-> ";
	cin >> x;

	cout << "Введите Y" << endl << "-> ";
	cin >> y;

	cout << "Введите цифру (0 - В, 1 - Г)" << endl << "-> ";
	cin >> code;

	// В
	if (code == 0) {
		cout << "Code 0!" << endl << "Processing..." << endl;
		if (((x * x) + ((y - 1) * (y - 1))) < 1 && 1 - (x * x) > y){
			cout << "(x, y) принадлежит D" << endl;
			u = x - y;
		}
		else{
			cout << "Увы, (x, y) не принадлежит D. Вы проиграли." << endl;
			u = x * y + 7;
		}
	}
	// Г
	else if (code == 1){
		cout << "Code 1!" << endl << "Processing..." << endl;
		if ((x > -1 && x < 1) && (y > 0 && y < 1) && ((x > 0.3 || x < 0) && (y > 0.3 && y > 0))){
			cout << "(x, y) принадлежит D" << endl;
			u = (x * x) - 1;
		} else {
			cout << "Увы, (x, y) не принадлежит D. Вы проиграли." << endl;
			u = sqrt((abs(x - 1)));
		}
	}
	else {
		cout << "ERROR!";
		return;
	}
	cout << "u= " << u << endl;
}

void task57(){
	int x = 0;
	double a = x;
	int code = 0;

	cout << "Введите x: " << endl << "-> ";
	cin >> x;

	cout << "Введите цифру (0 - В, 1 - Г)" << endl << "-> ";
	cin >> code;

	if (code == 0){
		cout << "Code 0!" << endl << "Processing..." << endl;
		if (x <= 0){
			cout << "x <= 0" << endl;
			a = 0;
		}
		else if ((0 < x) && (x <= 1)){
			cout << "0 < x <= 1" << endl;
			a = x;
		}
		else {
			cout << "???" << endl;
			a = (x * x * x * x);
		}
	}
	else if (code == 1){
		cout << "Code 1!" << endl << "Processing..." << endl;
		if (x <= 0){
			cout << "x <= 0" << endl;
			a = 0;
		}
		else if ((0 < x) && (x <= 1)){
			cout << "0 < x <= 1" << endl;
			a = (x * x) - x;
		}
		else {
			cout << "???" << endl;
			a = (x*x) - sin(3.14 * (x * x));
		}
	}
	else {
		cout << "ERROR!";
		return;
	}

	cout << "f(a) = " << a;
}

void task76(){
	int k;
	int l;
	int m;
	int n;

	cout << "Введите координаты лошади и желаемую точку: " << endl << "-> ";
	cin >> k;
	cin >> l;
	cin >> m;
	cin >> n;

	int limit = 8;

	if (k > limit || l > limit || m > limit || n > limit){
		cout << "Число не может быть выше 8. Это шахматы." << endl;
		return;
	}
	else if (k < 0 || l < 0 || m < 0 || n < 0){
		cout << "Число не может быть отрицательным. Это шахматы." << endl;
		return;
	}

	int code = 0;

	cout << "Введите цифру (0 - В, 1 - Г)" << endl << "-> ";
	cin >> code;

	if (code == 0){
		if ((k + 2 == m && l + 1 == n || k - 2 == m && l + 1 == n || k + 2 == m && l - 1 == n || k - 2 == m && l - 1 == n) || (k + 1 == m && l + 2 == n || k - 1 == m && l + 2 == n || k + 1 == m && l - 2 == n || k - 1 == m && l - 2 == n)){
			cout << "Угрожает!";
		}
		else {
			cout << "Не угрожает!";
		}
	}
	else if (code == 1){
		/// ???
		if (k == m || l == n){
			cout << "Одним ходом ? Запросто!";
		}
		if (k - m > 0){
			cout << "Ладье надо спуститься на " << k - m << endl;
		}
		else if (k - m < 0){
			cout << "Ладье надо подняться на " << (k - m) * -1 << endl;
		}

		if (l - n > 0){
			cout << "Ладье надо двигаться налево на " << l - n << endl;
		}
		else if (l - n < 0){
			cout << "Ладье надо двигаться вправо на " << (l - n) * -1 << endl;
		}

		// cout << "Not implemented.";
	}
	else {
		cout << "ERROR!";
		return;
	}
}

void task67(){
	int n = 0;
	cout << "Введите число N : " << endl << "-> ";

	cin >> n;

	int ne_N = n;
	int size = 0;

	while (ne_N != 0){
		ne_N /= 10;
		size++;
	}

	cout << "Мы сделали тяжелые математические посчеты. И мы узнали сколько цифр в вашем числе." << endl << "Количество ваших цифр -> " << size << endl;

	int Sot = n / 100;
	int Dec = (n / 10) % 10;
	int Ed = n % 10;
	int Summ = Sot + Dec + Ed;

	cout << "Мы также сделали очень тяжелые математические посчеты. И мы узнали сумму цифр в вашем числе." << endl << "Сумма ваших цифр -> " << Summ;
}

bool run = true;

int main(){
	setlocale(LC_ALL, "Russian");
	cout << "#######################" << endl;
	cout << "#     HELLO WORLD     #" << endl;
	cout << "#######################" << endl;

	while (run){
		int number = 0;

		cout << endl << "Avaliable tasks: " << 60 << ", " << 57 << ", " << 76 << ", " << 67 << endl;
		cout << "Write 0 for destroy this program" << endl;

		cout << "PUT NUMBER TASK HERE -> ";
		cin >> number;

		if (number == 0){
			run = false;
			cout << "#######################" << endl;
			cout << "#  PROGRAM DESTROYED  #" << endl;
			cout << "#######################" << endl;
			return 0;
		}

		cout << endl << "LET'S GO ?" << endl;
		cout << "#######################" << endl;
		cout << "TASK NUMBER " << number << " !!!" << endl << endl;

		//switch
		switch (number){
		case 60:
			task60();
			break;
		case 57:
			task57();
			break;
		case 76:
			task76();
			break;
		case 67:
			task67();
			break;
		default:
			cout << "WAIT. WUT ?! WHAT'S NUMBER ?!" << endl;
			break;
		}
		cout << endl << "#######################" << endl << endl;
	}
	return 0;
}