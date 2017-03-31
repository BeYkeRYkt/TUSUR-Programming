#include "BaseFigure.h"
#include "FigureInformation.h"
#include "ShowS.h"
#include "MoveFigure.h"
#include "Menu.h"
#include <iostream>

using namespace std;

void FigureInformation::operate(BaseFigure* pObj, Factory factory, Menu menu) {
	cout << "<-----: " << pObj->getName() << " :----->" << endl;
	cout << "Площадь: " << pObj->getSquare() << endl;
	cout << "Позиция X: " << pObj->getX() << endl;
	cout << "Позиция Y: " << pObj->getY() << endl;
	cin.get();
}

FigureInformation fI;