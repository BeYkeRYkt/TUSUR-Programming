#include "Tetragon.h"
#include <iostream>

using namespace std;

const string& Tetragon::getName() const{
	return name;
}

int Tetragon::getSquare() const{
	return A*H;
}

const bool Tetragon::isIntersect(BaseFigure* bf) const{
	//TODO: Implement BoundingBox
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
