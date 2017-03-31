#ifndef FigureInformation_h
#define FigureInformation_h
#include "Action.h"
#include "BaseFigure.h"

using namespace std;

class FigureInformation : public Action {
public:
	FigureInformation() : name("Get figure information") { }

	const string& getName() const{
		return name;
	}

	void operate(BaseFigure*, Factory, Menu);
private:
	string name;
};
extern FigureInformation fI;
#endif