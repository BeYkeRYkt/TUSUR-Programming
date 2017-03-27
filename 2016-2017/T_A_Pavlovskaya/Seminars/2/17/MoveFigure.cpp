#include "BaseFigure.h"
#include "MoveFigure.h"
#include <iostream>

using namespace std;

void MoveFigure::operate(BaseFigure* pObj) {
	move(pObj);
	cin.get();
}

void MoveFigure::move(BaseFigure* pObj){
	pObj->move();
}

// ֳכמבאכםי מבתוךע
MoveFigure move_fig;