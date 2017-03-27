#include "BaseFigure.h"
#include "Intersect.h"
#include "ShowS.h"
#include "MoveFigure.h"
#include <iostream>

using namespace std;

//Action* pActs[] = { &show_s, &move_fig, &intersect };
//vector<Action*> actionList(pActs, pActs + sizeof(pActs) / sizeof(Action*));

void Intersect::operate(BaseFigure* pObj) {
	//cout << pObj->getName() << ": ";
	//cout << pObj->getSquare() << endl;
	//Menu menu(actionList);
	//Factory factory;
	//BaseFigure* figure = menu.SelectObject(factory);
	//pObj->isIntersect(figure);
	//cin.get();
}

// ֳכמבאכםי מבתוךע
Intersect intersect;