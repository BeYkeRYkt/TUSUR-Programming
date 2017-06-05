#ifndef Tetragon_h
#define Tetragon_h

#include <iostream>
#include "BaseFigure.h"

using namespace std;

//Какой-то очень сложный тетрагон
class Tetragon : public BaseFigure {
public:
	Tetragon(string _name, int a, int h, int x, int y) : name(_name) {
		A = a;
		H = h;
		X = x;
		Y = y;
	}

	const string& getName() const;

	int getSquare() const;

	int getX() const;

	int getY() const;

	// По заданию
	const bool isIntersect(BaseFigure* bf) const;

	void move(int x, int y);
private:
	string name; //наме
	string val; //??
	int A, H; //Длина / Высота
	int X, Y; //координаты
};
#endif