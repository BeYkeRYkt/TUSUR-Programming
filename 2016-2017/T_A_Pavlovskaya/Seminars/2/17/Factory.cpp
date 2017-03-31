#include "Factory.h"
#include "Menu.h"
#include "Triangle.h"
#include "Tetragon.h"
#include <iostream>

using namespace std;

#define mX_LEN_STR 100

void Factory::AddObject(){
	cout << "Select object type:\n";
	cout << "1. Triangle" << endl;
	cout << "2. Tetragon" << endl;
	int type = Menu::SelectItem(2);

	int a, b;
	cout << "Введите A" << endl << "-> ";
	cin >> a;
	cout << "Введите B" << endl << "-> ";
	cin >> b;

	BaseFigure* bf;

	int x = 0;
	cout << "Введите позицию X" << endl << "-> ";
	cin >> x;

	int y = 0;
	cout << "Введите позицию Y" << endl << "-> ";
	cin >> y;

	switch (type){
	case 1:
		bf = new Triangle("Triagnle", a, b, x, y);
		break;
	case 2:
		bf = new Tetragon("Tetragon", a, b, x, y);
		break;
	}
	pObj.push_back(bf);
	cout << "Object added." << endl;
}

void Factory::DeleteObject(){
	int nItem = pObj.size();
	if (!nItem) {
		cout << "There are no objects." << endl;
		cin.get();
		return;
	}
	cout << endl;
	cout << "Delete one of the following Object:" << endl;
	for (int i = 0; i < nItem; ++i){
		cout << i + 1 << ". " << pObj[i]->getName() << endl;
	}
	int item = Menu::SelectItem(nItem);
	cin >> item;

	if (pObj[item - 1] == NULL){
		cout << "There are no object." << endl;
		cin.get();
		return;
	}

	string objName = pObj[item - 1]->getName();
	pObj.erase(pObj.begin() + item - 1);
	cout << "Object " << objName << " deleted." << endl;
	cin.get();
}