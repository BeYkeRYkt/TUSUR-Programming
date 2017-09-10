#include "BaseFigure.h"
#include "MoveFigure.h"
#include "Menu.h"
#include <iostream>

using namespace std;

void MoveFigure::operate(BaseFigure* pObj, Factory factory, Menu menu) {
	cout << "";
	move(pObj);
	cin.get();
}

void MoveFigure::move(BaseFigure* pObj){
	//TODO: Implement moving with x and y coordinates
	int x = 0;
	cout << "Введите X" << endl << "-> ";
	cin >> x;
	int y = 0;
	cout << "Введите Y" << endl << "-> ";
	cin >> y;
	pObj->move(x, y);
}

MoveFigure move_fig;