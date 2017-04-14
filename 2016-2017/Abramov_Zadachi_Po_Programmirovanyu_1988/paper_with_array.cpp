/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include <iostream>
#include <limits>

using namespace std;

/*
* Удаляет элемент из массива
*
* array - массив
* length - длина массива (с 1-ой)
* index - индекс (с 0)
*/
bool deleteElement(int *array, int length, int index){
	if (index > length || length < 1){
		cout << "Ошибка удаления" << endl;
		return false;
	}

	for (int ix = index; ix < length; ix++){
		array[ix] = array[ix + 1];
	}
	return true;
}

/*
* Добавление элемента в массив
*
* array - массив
* length - длина массива (с 1-ой)
* index - индекс (с 0)
* value - значение
*/
bool addElementToArray(int *&array, int length, int index, int value){
	//TODO: HIGH-end quality optimizaion without cache array
	if (index > length || length < 1){
		cout << "Ошибка добавления" << endl;
		return false;
	}

	int *arr = new int[length + 1]; // cache
	for (int i = 0; i < index; i++){
		arr[i] = array[i];
	}

	arr[index] = value;

	for (int ix = index; ix < length; ix++){
		arr[ix + 1] = array[ix];
	}
	delete array;
	array = arr;
	return true;
}

void task1(){
	const int N = 10;
	int *arr = new int[N];
	// int arr[N];

	cout << "Введите 10 целых чисел: " << endl << "-> ";
	// pulling array
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		arr[i] = value;
	}

	int max = numeric_limits<int>::min();
	int maxIndex = 0;

	// getting max
	for (int j = 0; j < N; j++){
		int value = arr[j];
		if (value > max){
			max = value;
			maxIndex = j;
		}
	}

	cout << "Максимальное элемент массива: " << max << endl;
	cout << "Индекс максимального числа: " << maxIndex << endl;

	deleteElement(arr, N, maxIndex);

	for (int i = 0; i < N - 1; i++){
		cout << arr[i] << "  ";
	}

	cout << endl;
	delete arr;
}

void task2(){
	//TODO: HIGH-end quality impromevent and normalize implementation
	int N = 10;
	int *arr = new int[N];
	//int arr[10];

	cout << "Введите 10 целых чисел: " << endl << "-> ";
	// pulling array
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		arr[i] = value;
	}

	// <!-- START -->
	// need first element check ?
	int first = arr[0];
	int second = arr[1];

	if (first > second){
		deleteElement(arr, N, 0);
	}
	else if (first < second){
		deleteElement(arr, N, 1);
	}
	N--;
	// <!-- End -->

	for (int i = 1; i < (N - 1); i++){
		int maxIndex = i;
		int a_prev = arr[i - 1];
		int a = arr[i];
		int a_post = arr[i + 1];

		if (a > a_prev && a > a_post){
			maxIndex = i;
		}
		else if (a_prev > a && a_prev > a_post){
			maxIndex = i - 1;
		}
		else if (a_post > a && a_post > a_prev){
			maxIndex = i + 1;
		}
		deleteElement(arr, N, maxIndex);
		N--;
		i--; // ???
	}


	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
	delete arr;
}

void task3(){
	//TODO: HIGH-end quality impromevent and normalize implementation
	int size = 10;
	int *arr = new int[size];
	//int arr[10];

	cout << "Введите 10 целых чисел: " << endl << "-> ";
	// pulling array
	for (int i = 0; i < size; i++){
		int value = 0;
		cin >> value;
		arr[i] = value;
	}

	int x = 0;
	cout << "Введите число X: " << endl << "-> ";
	cin >> x;

	for (int j = 0; j < size; j++){
		int value = arr[j];
		if (value > x){
			deleteElement(arr, size, j);
			size--;
			j--;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
	delete arr;
}

void task4(){
	//TODO: HIGH-end quality optimization
	const int N = 10;
	int *arr = new int[N];

	cout << "Введите 10 целых чисел: " << endl << "-> ";
	// pulling array
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		arr[i] = value;
	}

	int min = numeric_limits<int>::max();
	int minIndex = 0;

	int max = numeric_limits<int>::min();
	int maxIndex = 0;

	// getting min
	for (int j = 0; j < N; j++){
		int value = arr[j];
		if (value < min){
			min = value;
			minIndex = j;
		}
	}

	// getting max
	for (int j = 0; j < N; j++){
		int value = arr[j];
		if (value > max){
			max = value;
			maxIndex = j;
		}
	}
	// 0 , 1 , 2 
	addElementToArray(arr, N, 2, arr[minIndex] + arr[maxIndex]);

	for (int i = 0; i < N + 1; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
	delete arr;
}

void task5(){
	//TODO: HIGH-end quality optimization
	const int N = 10;
	int *arr = new int[N];

	cout << "Введите 10 целых чисел: " << endl << "-> ";
	// pulling array
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		arr[i] = value;
	}

	int M = N;
	for (int i = 0; i < M; i++){
		int value = arr[i];
		if(value % 2 == 0){
			addElementToArray(arr, M, i + 1, value * value);
			M++;
			i++;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cout << arr[i] << "  ";
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}