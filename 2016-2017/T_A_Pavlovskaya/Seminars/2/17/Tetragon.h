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

	const string& Tetragon::getName() const{
		return name; 
	}

	int Tetragon::getSquare() const{
		return A*H;
	}

	const bool Tetragon::isIntersect(BaseFigure* bf) const{
		if (bf->getX() == getX() || bf->getY() == getY()){
			return true;
		}
		return false;
	}

	int Tetragon::getX() const {
		return X;
	}

	int Tetragon::getY() const {
		return Y;
	}

	void Tetragon::move(int x, int y){
		X += x;
		Y += y;
		cout << getName() << " moved!" << endl;
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