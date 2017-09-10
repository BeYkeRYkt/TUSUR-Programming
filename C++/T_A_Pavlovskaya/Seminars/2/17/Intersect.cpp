#include "BaseFigure.h"
#include "Intersect.h"
#include "ShowS.h"
#include "MoveFigure.h"

#include "Menu.h"
#include "Factory.h"

#include <iostream>

using namespace std;

void Intersect::operate(BaseFigure* pObj, Factory factory, Menu menu) {
	cout << pObj->getName() << ": ";
	cout << pObj->getSquare() << endl;
	//TODO: Need more testing, huh ?
	BaseFigure* figure = menu.SelectObject(factory);
	if (pObj->isIntersect(figure)){
		cout << "Yes intersect!" << endl;
	}
	else{
		cout << "No.";
	}
	cin.get();
}

Intersect intersect;