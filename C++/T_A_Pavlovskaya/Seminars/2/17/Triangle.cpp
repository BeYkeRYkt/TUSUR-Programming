#include "Triangle.h"
#include <iostream>

using namespace std;

const string& Triangle::getName() const{
	return name;
}

int Triangle::getSquare() const{
	return 1.0 / 2.0 * (A * H);
}

const bool Triangle::isIntersect(BaseFigure* bf) const{
	//TODO: Implement BoundingBox
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