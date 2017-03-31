#include "BaseFigure.h"
#include "ShowS.h"
#include <iostream>
#include "Menu.h"

using namespace std;

void ShowS::operate(BaseFigure* pObj, Factory factory, Menu menu) {
	cout << pObj->getName() << ": ";
	cout << pObj->getSquare() << endl;
	cin.get();
}

ShowS show_s;