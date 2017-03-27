#include "Action.h"
#include "BaseFigure.h"
#include "Menu.h"
#include "Factory.h"

using namespace std;

class MoveFigure : public Action {
public:
	MoveFigure() : name("Move figure") { }
	const std::string& getName() const{
		return name;
	}
	void operate(BaseFigure* fig);
	void move(BaseFigure* fig);
private:
	string name;
};
extern MoveFigure move_fig;