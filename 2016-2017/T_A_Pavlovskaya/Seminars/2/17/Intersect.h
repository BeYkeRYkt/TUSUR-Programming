#include "Action.h"
#include "BaseFigure.h"
#include "Menu.h"
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