#ifndef BaseFigure_h
#define BaseFigure_h

#include <iostream>
#include <string>

using namespace std;

// Базовый класс для каких-то очень сложных фигур
class BaseFigure {
public:
	BaseFigure(string s = "") : name(s) {}

	virtual const double getSquare() const = 0;

	void move(){
		cout << name << ": YA SHEVELNULSYA!" << endl;
	}

	string getName(){
		return name;
	}

	virtual const bool isIntersect(BaseFigure* bf) const = 0;
protected:
	// Название фигуры
	string name;
};
#endif