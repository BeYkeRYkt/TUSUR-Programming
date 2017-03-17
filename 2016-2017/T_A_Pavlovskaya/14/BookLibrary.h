#ifndef BookLibrary_h
#define BookLibrary_h

#include <vector>
#include <string>

using namespace std;

struct Book{
	string name;
	string author;
	int year;

	Book(string author, string name, int year){
		this->author = author;
		this->name = name;
		this->year = year;
	}
};

class BookLibrary{
private:
	vector<Book*> lib;
public:
	void addBook(Book* book);

	void removeBook(Book* book);

	Book* search(string name);

	Book* search(int year);

	void viewAllBooks();

	int getIndex(Book* book);
};
#endif