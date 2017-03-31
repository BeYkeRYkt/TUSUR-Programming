#ifndef Triangle_h
#define Triangle_h

#include "BaseFigure.h"
#include <iostream>
#include <string>

using namespace std;

//Очень сложный класс треугольника
class Triangle : public BaseFigure {
public:
	Triangle(string _name, int a, int h, int x, int y) : name(_name) {
		A = a;
		H = h;
		X = x;
		Y = y;
	}

	const string& Triangle::getName() const{
		return name;
	}

	int Triangle::getSquare() const{
		return 1.0 / 2.0 * (A * H);
	}

	const bool Triangle::isIntersect(BaseFigure* bf) const{
		if (bf->getX() == getX() || bf->getY() == getY()){
			return true;
		}
		return false;
	}

	int Triangle::getX() const {
		return X;
	}

	int Triangle::getY() const {
		return Y;
	}

	void Triangle::move(int x, int y){
		X += x;
		Y += y;
		cout << getName() << " moved!";
		cout << "My new coordinates! " << endl;
		cout << "X:= " << X << endl;
		cout << "Y:= " << Y << endl;
	}
private:
	string name;
	string val;
	int A, H;
	int X, Y;
};
#endif