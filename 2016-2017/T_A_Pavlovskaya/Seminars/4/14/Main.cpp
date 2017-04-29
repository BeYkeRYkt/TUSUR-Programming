#include "Note.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int noteSize = 8;
int availableSize = 0;
Note* notes = new Note[noteSize];

int getThreeIntegers(int phoneNumber){
	int a = 0;
	while (phoneNumber > 100) phoneNumber /= 10;
	return phoneNumber;
}

/**
*a - массив, length - длина массива
*/
void insertSort(Note* a, int length){
	//insertSort
	int i, j;
	for (i = 1; i < length; i++){
		Note x = a[i];
		j = i;
		while (j > 0 && getThreeIntegers(a[j - 1].getPhoneNumber()) > getThreeIntegers(x.getPhoneNumber())){
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = x;
	}
}

void inputNote(int index){
	cin.clear(); //fix
	cout << "Person #" << (index + 1) << ": " << std::endl;
	cout << "Input family name: ";

	string family = "NULLABLE";
	cin >> family;
	notes[index].setFamilyName(family);

	cout << "Input name: ";
	string name = "NULL";
	cin >> name;
	notes[index].setName(name);

	cout << "Input the birthday: ";
	int* date = new int[3];
	for (int j = 0; j < 3; j++) {
		cin >> date[j];
	}
	notes[index].setDate(date);

	cout << "Input the phone number: ";
	int phone;
	cin >> phone;
	notes[index].setPhoneNumber(phone);
	cout << endl;

	availableSize++;
	insertSort(notes, availableSize);
}

void inputInformation()
{
	for (int i = 0; i < noteSize; i++) {
		inputNote(i);
	}
}

void search(string family){
	int found = 0;
	for (int i = 0; i < noteSize; i++){
		if (notes[i].getFamilyName() == family){
			found++;
		}
	}
	if (found == 0){
		cout << "No found." << endl;
		return;
	}

	for (int i = 0; i < noteSize; i++){
		if (notes[i].getFamilyName() == family){
			cout << notes[i].getFamilyName() << " " << notes[i].getName() << " " << notes[i].getPhoneNumber() << " ";
			cout << notes[i].getDate()[0] << ".";
			cout << notes[i].getDate()[1] << ".";
			cout << notes[i].getDate()[2] << endl;
		}
	}
}

void viewAllNotes(){
	cout << "All notes: " << endl;
	for (int i = 0; i < availableSize; i++){
		cout << notes[i].getFamilyName() << " " << notes[i].getName() << " " << notes[i].getPhoneNumber() << " ";
		cout << notes[i].getDate()[0] << ".";
		cout << notes[i].getDate()[1] << ".";
		cout << notes[i].getDate()[2] << endl;
	}
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool run = true;
	while (run){
		cin.clear(); //fix
		cout << "0. Exit" << endl << endl;
		cout << "1. Create 8 notes" << endl;
		cout << "2. Create note in index" << endl;
		cout << "3. Search note from family name" << endl;
		cout << "4. View all notes" << endl;
		cout << endl << "--> ";

		int code = 0;
		cin >> code;

		switch (code){
		case 0:
			run = false;
			break;
		case 1:
			inputInformation();
			break;
		case 2:{
				   int index = 0;
				   cout << "Index: ";
				   cin >> index;
				   inputNote(index - 1);
				   break;
		}
		case 3:{
				   string family = "";
				   cout << "Family (?): ";
				   cin >> family;
				   search(family);
				   break;
		}
		case 4:
			viewAllNotes();
			break;
		default:
			cout << "Unknown command" << endl;
			break;
		}
	}
	return 0;
}