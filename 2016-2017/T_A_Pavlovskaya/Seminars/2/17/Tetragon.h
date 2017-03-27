#ifndef Tetragon_h
#define Tetragon_h

#include <iostream>
#include "BaseFigure.h"

using namespace std;

//Какой-то очень сложный тетрагон
class Tetragon : public BaseFigure {
protected:
	int A;
	int H;
public:
	Tetragon(int a, int b) : BaseFigure("Tetragon") {
		A = a;
		H = b;
	}

	const double Tetragon::getSquare() const{
		return A*H;
	}

	void Tetragon::move(){
		cout << "I'm Tetragon" << endl;
		BaseFigure::move();
	}

	const bool Tetragon::isIntersect(BaseFigure* bf) const{
		return true;
	}
};
#endif