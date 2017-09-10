#ifndef SHOWS_H
#define SHOWS_H
#include "Action.h"
#include "BaseFigure.h"
#include "Factory.h"

using namespace std;

class ShowS : public Action {
public:
	ShowS() : name("Show square figure") { }

	const string& getName() const{
		return name;
	}

	void operate(BaseFigure* fig, Factory, Menu);
private:
	string name;
};
extern ShowS show_s;
#endif