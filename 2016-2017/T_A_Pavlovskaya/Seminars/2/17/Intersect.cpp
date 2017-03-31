#include "BaseFigure.h"
#include "Intersect.h"
#include "ShowS.h"
#include "MoveFigure.h"
#include <iostream>

using namespace std;

void Intersect::operate(BaseFigure* pObj) {
	cout << pObj->getName() << ": ";
	cout << pObj->getSquare() << endl;
	//TODO: Need more testing, huh ?
	//BaseFigure* figure = menu.SelectObject(fctry);
	//pObj->isIntersect(figure);
	cin.get();
}

Intersect intersect;