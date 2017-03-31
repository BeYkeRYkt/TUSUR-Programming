#include "BaseFigure.h"
#include "Tetragon.h"
#include "Triangle.h"

#include "Action.h"
#include "ShowS.h"
#include "MoveFigure.h"
#include "Intersect.h"

#include "Factory.h"
#include "Menu.h"

#include <iostream>
#include <Windows.h>

using namespace std;

Action* pActs[] = { &show_s, &move_fig, &intersect};
vector<Action*> actionList(pActs,
	pActs + sizeof(pActs)/sizeof(Action*));

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Factory factory;
	Menu menu(actionList);
	JobMode jobMode;

	while ((jobMode = menu.SelectJob()) != Exit) {
		switch (jobMode) {
		case AddObj: factory.AddObject();
			break;
		case DelObj: factory.DeleteObject();
			break;
		case WorkWithObj:
			BaseFigure* pObj = menu.SelectObject(factory);
			Action* pAct = menu.SelectAction(pObj);
			if (pAct){
				pAct->operate(pObj);
			}
			break;
		}
	}
	cin.get();
	cout << "Bye!\n";
	return 0;
}
