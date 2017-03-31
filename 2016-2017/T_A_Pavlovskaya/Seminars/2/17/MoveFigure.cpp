#include "BaseFigure.h"
#include "MoveFigure.h"
#include <iostream>

using namespace std;

void MoveFigure::operate(BaseFigure* pObj) {
	cout << "";
	move(pObj);
	cin.get();
}

void MoveFigure::move(BaseFigure* pObj){
	//TODO: Implement moving with x and y coordinates
	pObj->move(0, 0);
}

MoveFigure move_fig;