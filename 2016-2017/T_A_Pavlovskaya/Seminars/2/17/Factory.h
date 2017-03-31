#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include "BaseFigure.h"

using namespace std;

class Factory {
	friend class Menu;
public:
	Factory(){}
	void AddObject();
	void DeleteObject();
private:
	vector<BaseFigure*> pObj;
};
#endif