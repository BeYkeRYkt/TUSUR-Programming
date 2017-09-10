#include <iostream>
#include "DequeError.h"
#include <list>

using namespace std;

//Page 143
template <typename T> 
class Deque
{
private:
	list<T> l;
public:
	/*
	* Добавляет элемент в начало очереди. Этот элемент будет взят из очереди следующим при вызове метода DequeueFirst.
	*/
	void enqueueFirst(T value);

	/*
	* Добавляет элемент в конец очереди. Этот элемент будет взят из очереди следующим при вызове метода DequeueLast.
	*/
	void enqueueLast(T value);

	/*
	* Удаляет элемент из начала очереди и возвращает его. Если очередь пустая, кидает InvalidOperationException.
	*/
	T dequeueFirst();

	/*
	* Удаляет элемент с конца очереди и возвращает его. Если очередь пустая, кидает InvalidOperationException
	*/
	T dequeueLast();

	/*
	* Возвращает элемент из начала очереди, не изменяя ее. Если очередь пустая, кидает InvalidOperationException.
	*/
	T peekFirst();

	/*
	* Возвращает элемент с конца очереди, не изменяя ее. Если очередь пустая, кидает InvalidOperationException.
	*/
	T peekLast();

	/*
	* Возвращает количество элементов в очереди или 0, если очередь пустая.
	*/
	int getQueueCount();

	void showQueue();

	void generateError();

	void generateRangeError();

	void generateNullError();
private:
	T getValue(int index);
};

//Implementation
template <typename T>
void Deque<T>::enqueueFirst(T value){
	l.push_front(value);
}

template <typename T>
void Deque<T>::enqueueLast(T value){
	l.push_back(value);
}

template <typename T>
T Deque<T>::dequeueFirst(){
	T t = l.front();
	l.remove(t);
	return t;
}

template <typename T>
T Deque<T>::dequeueLast(){
	T t = l.back();
	l.remove(t);
	return t;
}

template <typename T>
T Deque<T>::peekFirst(){
	T t = l.front();
	return t;
}

template <typename T>
T Deque<T>::peekLast(){
	T t = l.back();
	return t;
}

template <typename T>
int Deque<T>::getQueueCount(){
	return l.size();
}

template <typename T>
void Deque<T>::showQueue(){
	if (l.size() == 0){
		cout << "List empty,nothing to display" << endl;
		return;
	}

	cout << "The Doubly Link List is :" << endl;
	for (typename list<T>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << (*it) << " <-> ";
	}
	cout << "NULL" << endl;
}

template <typename T>
void Deque<T>::generateError(){
	try{
		throw DequeError();
	}
	catch (DequeError& er){
		er.ErrMsg();
	}
}

template <typename T>
void Deque<T>::generateRangeError(){
	try{
		throw DequeRangeError(0, getQueueCount() - 1, 90);
	}
	catch (DequeError& er){
		er.ErrMsg();
	}
}

template <typename T>
void Deque<T>::generateNullError(){
	try{
		throw DequeNullPointerError();
	}
	catch (DequeError& er){
		er.ErrMsg();
	}
}