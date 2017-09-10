/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include<iostream>
#include<ctime>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//PART 1: 
bool isPerfectSquare(int number){
	if (sqrt(number)*sqrt(number) == number){
		return true;
	}
	return false;
}

void task440a(){
	int i, n, lenght, maxlenght;
	cout << "Введите длинну последовательности: " << endl << "-> ";
	cin >> n;
	int *a = new int[n];
	cout << "Введите последовательность: " << endl << "->";
	for (i = 0; i < n; i++){
		cin >> a[i];
	}

	//Random ?
	/* for (i = 0; i < n; i++){
		a[i] = rand() & 101;
	} */

	cout << "Максимальная длинна отрезка полных квадратов: " << endl;
	maxlenght = 0;
	for (i = 0; i < n; i++)
	{
		lenght = 0;
		while (isPerfectSquare(a[i]))
		{
			lenght++;
			i++;
		}
		if (lenght>maxlenght)
			maxlenght = lenght;
	}
	cout << maxlenght;
	delete a;
}

void procedure(int startIndex, int lenght, char* arr){
	for (int i = startIndex - 1; i < lenght; i++){
		if (arr[i] == '0'){
			arr[i] = '1';
		}
		else if (arr[i] == '1'){
			arr[i] = '0';
		}
		cout << arr[i];
	}
}

void task466(){
	int N = 0;
	cout << "Введите длину: " << endl << "-> ";
	cin >> N;

	int x = 0;
	cout << "Введите позицию строки: " << endl << "-> ";
	cin >> x;
	char* arr = new char[];

	cout << "Введите числа" << endl << "- >";
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	procedure(x, N, arr);
	//delete arr; - error issue
}

void write(string filename, char* buffer){
	fstream inputFile(filename, ofstream::out | ofstream::trunc);
	if (!inputFile.is_open()){
		return;
	}
	inputFile << buffer;
	inputFile.close();
}

void copypasta(string fileName1, string fileName2, bool show){
	fstream inputFile(fileName1);
	if (!inputFile.is_open()){
		cout << "error";
		return;
	}
	inputFile.seekg(0, inputFile.end);
	int length = inputFile.tellg();
	inputFile.seekg(0, inputFile.beg);

	char* input_buffer = new char[length+1];
	inputFile.read(input_buffer, length);
	input_buffer[length] = 0;

	if (show){
		cout << input_buffer;
	}
	write(fileName2, input_buffer);
	inputFile.close();
	delete[] input_buffer;
}

// PART 2:
void task477(){
	string file1name = "f1_477.txt";
	string file2name = "f2_477.txt";
	string fileHname = "f3_h.txt";

	//f1 --> h
	copypasta(file1name, fileHname, true);
	//f2 --> f1
	copypasta(file2name, file1name, true);
	//h file buffer
	copypasta(fileHname, file2name, true);
}

void task496b(){
	
	string file1name = "f1_496b.txt";
	string file2name = "g1_496b.txt";
	const int size = 500;

	fstream inputFile1(file1name);
	fstream inputFile2(file2name);

	if (!inputFile1.is_open() || !inputFile2.is_open()){
		cout << "error";
		return;
	}

	char* input_buffer = new char[size]();
	char* input_buffer1 = new char[size]();
	char* filtered_buffer = new char[size]();

	int i = 0;
	while (inputFile1.read(input_buffer, 1)){
		if (input_buffer[0] != '\n'){
			input_buffer1[i] = input_buffer[0];
			i++;
		}
	}

	int k = 0;
	for (int j = 0; j < i - 1; j++){
		if (input_buffer1[j + 1] == 'a'){
			filtered_buffer[k] = input_buffer1[j];
			cout << input_buffer[k];
			k++;
		}
	}

	inputFile1.close();
	inputFile2 << filtered_buffer;
	inputFile2.close();
}

struct Record {
	char name[50];
	char fam[50];
	char class1[50];

};

//507, 477б 466
void task507b(){
	int k = 0, n = 0;

	vector<Record> records;
	fstream file("f1_507b.txt");
	if (!file.is_open()){
		cout << "error";
		return;
	}

	if (file.bad()) {
		std::cout << "Ошибка чтения" << endl;
		return;
	}
	if (file.eof()) {
		std::cout << "Неизвестный символ" << endl;
		return;
	}

	Record tmp;
	while (file >> tmp.fam >> tmp.name >> tmp.class1){
		records.push_back(tmp);
		n++;
	}
	file.close();

	int count = 0;
	for (int i = 0; i < n - 1; i++){
		int number1 = records[i].class1[0];
		for (int j = i+1; j < n; j++)
		{
			int number2 = records[j].class1[0];
			if (strcmp(records[i].fam, records[j].fam) == 0 && number1 == number2 && strcmp(records[i].name, records[j].name) != 0)
			{
				count++;
			}
		}
	}
	if (count > 0 && count < 2){
		count++;
	}
	cout << "Кол-во однофамильцев: " << count;
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 440 << " " << 466 << " " << 477 << " "<< 496 << " " << 507 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 440:
			task440a();
			break;
		case 466:
			task466();
			break;
		case 477:
			task477();
			break;
		case 496:
			task496b();
			break;
		case 507:
			task507b();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}