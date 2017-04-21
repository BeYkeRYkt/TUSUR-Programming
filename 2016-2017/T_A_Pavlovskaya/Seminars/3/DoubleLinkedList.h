/**
* Imported from Abramyan_20 and modified for Pavlovskaya's tasks
**/
#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h
#include <iostream>

using namespace std;

//Что-то типо элемента
template <typename T>
struct Node
{
	T info;
	Node* next; //След. элемент
	Node* prev; //Пред. элемент
};

//Double LinkedList implementation
template<typename T>
class DoubleLinkedList
{
public:
	void createList(T value);
	void addBegin(T value);
	void addAfter(T value, int position);
	void deleteElement(T value);
	void deleteElementFromIndex(int index);
	Node<T>* searchElement(int index);
	void displayList();
	int getCount();
	void reverse();
	DoubleLinkedList() : start(){};
private:
	Node<T>* start;
};


template <typename T>
void DoubleLinkedList<T>::createList(T value)
{
	Node<T> *s, *temp;
	temp = new Node<T>();
	temp->info = value;
	temp->next = NULL;

	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		s = start;
		while (s->next != NULL){
			s = s->next;
		}
		s->next = temp;
		temp->prev = s;
	}
}


template <typename T>
void DoubleLinkedList<T>::addBegin(T value)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		createList(value);
		return;
	}

	Node<T>* temp = new Node<T>();
	temp->prev = NULL;
	temp->info = value;
	temp->next = start;
	start->prev = temp;
	start = temp;

	cout << "Element Inserted" << endl;
}


template<typename T>
void DoubleLinkedList<T>::addAfter(T value, int index)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		createList(value);
		return;
	}

	Node<T> *tmp, *q;
	int i;
	q = start;
	for (i = 0; i < index; i++)
	{
		q = q->next;
		if (q == NULL)
		{
			cout << "There are less than ";
			cout << index + 1 << " elements." << endl;
			return;
		}
	}

	tmp = new Node<T>();
	tmp->info = value;

	if (q->next == NULL)
	{
		q->next = tmp;
		tmp->next = NULL;
		tmp->prev = q;
	}
	else
	{
		tmp->next = q->next;
		tmp->next->prev = tmp;
		q->next = tmp;
		tmp->prev = q;
	}
	cout << "Element Inserted" << endl;
}


template <typename T>
void DoubleLinkedList<T>::deleteElement(T value){
	Node<T> *tmp, *q;
	if (start->info == value)
	{
		tmp = start;
		if (start->next != NULL){
			start = start->next;
			start->prev = NULL;
		}
		start = NULL;
		delete start;
		cout << "Element Deleted" << endl;
		delete tmp;
		return;
	}

	q = start;

	while (q->next->next != NULL){
		if (q->next->info == value)
		{
			tmp = q->next;
			q->next = tmp->next;
			tmp->next->prev = q;
			cout << "Element Deleted" << endl;
			delete tmp;
			return;
		}
		q = q->next;
	}

	if (q->next->info == value){
		tmp = q->next;
		delete tmp;
		q->next = NULL;
		cout << "Element Deleted" << endl;
		return;
	}
	cout << "Element " << value << " not found" << endl;
}

template <typename T>
void DoubleLinkedList<T>::deleteElementFromIndex(int index){
	Node<T>* current = searchElement(index);
	deleteElement(current->info);
}

template <typename T>
Node<T>* DoubleLinkedList<T>::searchElement(int index){
	Node<T>* current = start;
	int count = 0;
	if (start == NULL){
		return NULL;
	}

	while (current->next != NULL && count != index){
		current = current->next;
		count++;
	}
	return current;
}

template <typename T>
void DoubleLinkedList<T>::displayList()
{
	Node<T> *q;
	if (start == NULL)
	{
		cout << "List empty,nothing to display" << endl;
		return;
	}

	q = start;
	cout << "The Doubly Link List is :" << endl;
	while (q != NULL)
	{
		cout << q->info << " <-> ";
		q = q->next;
	}
	cout << "NULL" << endl;
}

template <typename T>
int DoubleLinkedList<T>::getCount()
{
	Node<T> *q = start;
	int cnt = 0;

	while (q != NULL)
	{
		q = q->next;
		cnt++;
	}
	return cnt;
}

template <typename T>
void DoubleLinkedList<T>::reverse()
{
	Node<T> *p1, *p2;
	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;

	while (p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
	cout << "List Reversed" << endl;
}
#endif