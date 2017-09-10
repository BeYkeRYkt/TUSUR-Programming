#include <iostream>
#include "DoubleLinkedList.h"
#include "DequeError.h"

using namespace std;

template <typename T> 
class Deque
{
private:
	DoubleLinkedList<T> list;
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
	list.addBegin(value);
}

template <typename T>
void Deque<T>::enqueueLast(T value){
	list.addAfter(value, getQueueCount() - 1);
}

template <typename T>
T Deque<T>::dequeueFirst(){
	T t = getValue(0);
	list.deleteElementFromIndex(0);
	return t;
}

template <typename T>
T Deque<T>::getValue(int index){
	if (index > getQueueCount() - 1){
		throw DequeRangeError(0, getQueueCount() - 1, index);
	}
	Node<T>* node = list.searchElement(index);
	if (node == NULL){
		throw DequeNullPointerError();
	}
	return node->info;
}

template <typename T>
T Deque<T>::dequeueLast(){
	T t = getValue(list.getCount() - 1);
	list.deleteElementFromIndex(list.getCount() - 1);
	return t;
}

template <typename T>
T Deque<T>::peekFirst(){
	T t = getValue(0);
	return t;
}

template <typename T>
T Deque<T>::peekLast(){
	T t = getValue(list.getCount() - 1);
	return t;
}

template <typename T>
int Deque<T>::getQueueCount(){
	return list.getCount();
}

template <typename T>
void Deque<T>::showQueue(){
	list.displayList();
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