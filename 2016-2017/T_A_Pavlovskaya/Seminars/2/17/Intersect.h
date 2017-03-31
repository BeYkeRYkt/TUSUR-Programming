#ifndef INTERSECT_H
#define INTERSECT_H
#include "Action.h"
#include "BaseFigure.h"
#include "Factory.h"

using namespace std;

class Intersect : public Action {
public:
	Intersect() : name("Check Intersect") { }

	const string& getName() const{ 
		return name; 
	}

	void operate(BaseFigure*);

	bool isIntersect(BaseFigure*, BaseFigure*);
private:
	string name;
};
extern Intersect intersect;
#endif