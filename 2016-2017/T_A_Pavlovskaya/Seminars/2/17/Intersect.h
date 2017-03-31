#ifndef INTERSECT_H
#define INTERSECT_H
#include "Action.h"
#include "BaseFigure.h"

using namespace std;

class Intersect : public Action {
public:
	Intersect() : name("Check Intersect") { }

	const string& getName() const{ 
		return name; 
	}

	void operate(BaseFigure*, Factory, Menu);

	bool isIntersect(BaseFigure*, BaseFigure*);
private:
	string name;
};
extern Intersect intersect;
#endif