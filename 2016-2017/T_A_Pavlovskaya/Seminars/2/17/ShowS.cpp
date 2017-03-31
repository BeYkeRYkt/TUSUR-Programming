#include "BaseFigure.h"
#include "ShowS.h"
#include <iostream>

using namespace std;

void ShowS::operate(BaseFigure* pObj) {
	cout << pObj->getName() << ": ";
	cout << pObj->getSquare() << endl;
	cin.get();
}

ShowS show_s;