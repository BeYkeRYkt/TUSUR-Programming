#include <iostream>
#include <Windows.h>

#include "BookLibrary.h"

BookLibrary lib = BookLibrary();
bool DEBUG = false;

void logDebug(string text){
	cout << endl << "[DEBUG] " << text << endl;
}

void addBook(string author, string name, int year){
	if (lib.search(name) != NULL){
		cout << "����� ��� ����������." << endl;
		return;
	}

	Book* book = new Book(author, name, year);
	lib.addBook(book);

	if (DEBUG && lib.search(name) != NULL){
		logDebug("Book " + name + " has been added");
	}
}

void removeBook(Book* book){
	lib.removeBook(book);
	if (DEBUG && lib.search(book->name) == NULL){
		logDebug("Book " + book->name + " has been removed");
	}
}

void testing(){
	cout << "Testing..." << endl;
	DEBUG = true;

	//Add book
	cout << "Adding book's...";
	addBook("DevelopedOne", "The Fallen Fox", 2017);
	addBook("DevelopedOne", "Hardbook", 2017);
	addBook("123", "13", 1014);
	addBook("Kazerad", "Prequel or making a cat cry", 2011);
	lib.viewAllBooks();

	cout << endl;

	//Get book from name
	Book* book = lib.search("The Fallen Fox");
	cout << "<!--- Book info ---!>" << endl;
	cout << "Name: " << book->name << endl;
	cout << "Author: " << book->author << endl;
	cout << "Year: " << book->year << endl;

	cout << endl;

	//Get book from year
	Book* booky = lib.search(1014);
	cout << "<!--- Book info ---!>" << endl;
	cout << "Name: " << booky->name << endl;
	cout << "Author: " << booky->author << endl;
	cout << "Year: " << booky->year << endl;

	cout << endl;

	//Search remove book
	removeBook(book);
	removeBook(booky);

	lib.viewAllBooks();

	DEBUG = false;

}

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool run = true;

	while (run){
		int i = 0;
		cout << "������� ����������" << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. ����� ����� �� ��������" << endl;
		cout << "4. ����� ����� �� ����" << endl;
		cout << "5. �������� ��� �����" << endl;
		cout << "6. ������� ����" << endl;
		cout << endl << "0. - �����" << endl;
		cout << "-> ";
		cin >> i;

		switch (i){
		case 0:
			run = false;
			break;
		case 1:{
				   string name, author;
				   int year;
				   cout << endl << "������� ������" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, author);
				   cout << endl << "������� ��������" << endl << "-> ";
				   getline(cin, name);
				   cout << endl << "������� ���" << endl << "-> ";
				   cin >> year;

				   addBook(author, name, year);
				   cout << endl;
		}
			break;
		case 2:{
				   string name = NULL;
				   cout << endl << "������� ��������" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, name);
				   Book* book = lib.search(name);
				   if (book != NULL){
					   removeBook(book);
					   cout << "����� ������� �� ����������. " << endl;
				   }
				   else{
					   cout << "����� ����� �� ����������." << endl;
				   }
				   cout << endl;
		}
			break;
		case 3:{
				   string name = NULL;
				   cout << endl << "������� ��������" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, name);

				   Book* book = lib.search(name);

				   if (book != NULL){
					   cout << "<!--- ���������� ---!>" << endl;
					   cout << "��������: " << book->name << endl;
					   cout << "�����: " << book->author << endl;
					   cout << "���: " << book->year << endl;
				   }
				   else{
					   cout << "����� ����� �� ����������.";
				   }
				   cout << endl;
		}
			break;
		case 4:{
				   int year = 0;
				   cout << endl << "������� ���" << endl << "-> ";
				   cin >> year;

				   Book* book = lib.search(year);

				   if (book != NULL){
					   cout << "<!--- ���������� ---!>" << endl;
					   cout << "��������: " << book->name << endl;
					   cout << "�����: " << book->author << endl;
					   cout << "���: " << book->year << endl;
				   }
				   else{
					   cout << "����� ����� �� ����������.";
				   }
				   cout << endl;
		}
			break;
		case 5:
			lib.viewAllBooks();
			cout << endl;
			break;
		case 6:
			testing();
			break;
		default:
			cout << "����������� �����.";
			break;
		}
	}
}