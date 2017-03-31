#ifndef ACTION_H
#define ACTION_H

#include "BaseFigure.h"
#include <string>

using namespace std;

class Action {
public:
	virtual ~Action(){}
	virtual void operate(BaseFigure*) = 0;
	virtual const string& getName() const = 0;
};
#endif