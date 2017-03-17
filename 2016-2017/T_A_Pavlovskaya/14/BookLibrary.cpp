#include <string>
#include <vector>
#include <iostream>

#include "BookLibrary.h"

using namespace std;

void BookLibrary::addBook(Book* book){
	lib.push_back(book);
}

void BookLibrary::removeBook(Book* book){
	lib.erase(lib.begin() + getIndex(book));
}

Book* BookLibrary::search(string name){
	for (Book* book : lib){
		if (book->name == name){
			return book;
		}
	}
	return NULL;
}

Book* BookLibrary::search(int year){
	for (Book* book : lib){
		if (book->year == year){
			return book;
		}
	}
	return NULL;
}

void BookLibrary::viewAllBooks(){
	cout << "All books:" << endl;
	for (int i = 0; i < lib.size(); i++){
		cout << i + 1 << ". " << lib[i]->name << " " << lib[i]->year << endl;
	}
}

int BookLibrary::getIndex(Book* book){
	int index = 0;
	for (Book* b : lib){
		if (b->name == book->name){
			break;
		}
		index++;
	}
	return index;
}
