/////////////////////////////////////////////////////
// Menu.h
#include "BaseFigure.h"
#include "Action.h"
#include "Factory.h"
#include <vector>

using namespace std;

typedef enum { AddObj, DelObj, WorkWithObj, Exit } JobMode;

class Menu {
public:
	Menu(vector<Action*>);
	JobMode SelectJob() const;
	BaseFigure* SelectObject(const Factory&) const;
	Action* SelectAction(const BaseFigure*) const;
	static int SelectItem(int);
private:
	vector<Action*> pAct;
};