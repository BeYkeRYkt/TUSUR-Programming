#ifndef ACTION_H
#define ACTION_H

#include "BaseFigure.h"
#include "Factory.h"
#include <string>

using namespace std;

class Action {
public:
	virtual ~Action(){}
	virtual void operate(BaseFigure*, Factory, Menu) = 0;
	virtual const string& getName() const = 0;
};
#endif