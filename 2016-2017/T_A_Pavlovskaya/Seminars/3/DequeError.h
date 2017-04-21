#ifndef DequeError_h
#define DequeError_h

#define DEBUG

#include <iostream>

using namespace std;

class DequeError {
public:
	DequeError(){}
	virtual void ErrMsg() const{
		cerr << "Error with Deque object.\n";
	}
	void Continue() const{
#ifdef DEBUG
		cerr << "Debug: program is being continued.\n";
#else
	throw;
#endif
	}
};

class DequeRangeError : public DequeError {
public:
	DequeRangeError(int _min, int _max, int _actual) : mmin(_min), mmax(_max), actual(_actual) {}
	void ErrMsg() const{
		cerr << "Error of Index: ";
		cerr << "possible range: " << mmin << " - " <<
			mmax << ", ";
		cerr << "actual Index: " << actual << endl;
		Continue();
	}
private:
	int mmin;
	int mmax;
	int actual;
};

class DequeNullPointerError : public DequeError {
public:
	DequeNullPointerError(){}
	void ErrMsg() const{
		cerr << "Error of NullPointerException \n";
		Continue();
	}
};
#endif
