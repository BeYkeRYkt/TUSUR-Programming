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
		cout << "Книга уже существует." << endl;
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
		cout << "Книжная библиотека" << endl;
		cout << "1. Добавить книгу" << endl;
		cout << "2. Удалить книгу" << endl;
		cout << "3. Поиск книги по названию" << endl;
		cout << "4. Поиск книги по дате" << endl;
		cout << "5. Показать все книги" << endl;
		cout << "6. Быстрый тест" << endl;
		cout << endl << "0. - Выход" << endl;
		cout << "-> ";
		cin >> i;

		switch (i){
		case 0:
			run = false;
			break;
		case 1:{
				   string name, author;
				   int year;
				   cout << endl << "Введите автора" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, author);
				   cout << endl << "Введите название" << endl << "-> ";
				   getline(cin, name);
				   cout << endl << "Введите год" << endl << "-> ";
				   cin >> year;

				   addBook(author, name, year);
				   cout << endl;
		}
			break;
		case 2:{
				   string name = NULL;
				   cout << endl << "Введите название" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, name);
				   Book* book = lib.search(name);
				   if (book != NULL){
					   removeBook(book);
					   cout << "Книга удалена из библиотеки. " << endl;
				   }
				   else{
					   cout << "Такой книги не существует." << endl;
				   }
				   cout << endl;
		}
			break;
		case 3:{
				   string name = NULL;
				   cout << endl << "Введите название" << endl << "-> ";
				   cin.get(); //fix
				   getline(cin, name);

				   Book* book = lib.search(name);

				   if (book != NULL){
					   cout << "<!--- Информация ---!>" << endl;
					   cout << "Название: " << book->name << endl;
					   cout << "Автор: " << book->author << endl;
					   cout << "Год: " << book->year << endl;
				   }
				   else{
					   cout << "Такой книги не существует.";
				   }
				   cout << endl;
		}
			break;
		case 4:{
				   int year = 0;
				   cout << endl << "Введите год" << endl << "-> ";
				   cin >> year;

				   Book* book = lib.search(year);

				   if (book != NULL){
					   cout << "<!--- Информация ---!>" << endl;
					   cout << "Название: " << book->name << endl;
					   cout << "Автор: " << book->author << endl;
					   cout << "Год: " << book->year << endl;
				   }
				   else{
					   cout << "Такой книги не существует.";
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
			cout << "Неизвестный номер.";
			break;
		}
	}
}