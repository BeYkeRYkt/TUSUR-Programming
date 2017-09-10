#ifndef BaseFigure_h
#define BaseFigure_h

#include <iostream>
#include <string>

using namespace std;

// Базовый класс для каких-то очень сложных фигур
class BaseFigure {
public:
	virtual ~BaseFigure(){};
	virtual const string& getName() const = 0;
	virtual int getSquare() const = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual const bool isIntersect(BaseFigure* bf) const = 0;
	virtual void move(int x, int y){} //hotfix
};
#endif