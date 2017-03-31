#ifndef MoveFigure_h
#define MoveFigure_h
#include "Action.h"
#include "BaseFigure.h"

using namespace std;

class MoveFigure : public Action {
public:
	MoveFigure() : name("Move figure") { }
	const std::string& getName() const{
		return name;
	}
	void operate(BaseFigure*, Factory, Menu);
	void move(BaseFigure*);
private:
	string name;
};
extern MoveFigure move_fig;
#endif