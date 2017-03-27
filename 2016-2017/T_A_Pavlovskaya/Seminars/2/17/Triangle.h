#ifndef Triangle_h
#define Triangle_h

#include "BaseFigure.h"
#include <iostream>

using namespace std;

//ќчень сложный класс дл¤ треугольника
class Triangle : public BaseFigure {
protected:
	int A;
	int H;
public:
	Triangle(int a, int b) : BaseFigure("Triangle") {
		A = a;
		H = b;
	}

	const double Triangle::getSquare() const{
		return 1.0 / 2.0 * (A * H);
	}

	void Triangle::move(){
		cout << "I'm Triangle" << endl;
		BaseFigure::move();
	}

	const bool Triangle::isIntersect(BaseFigure* bf) const{
		return false;
	}
};
#endif