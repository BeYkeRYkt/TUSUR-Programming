/**
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 - 2020 D3v3l0p3d_0n3
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *  
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

struct Item {
	int info;
	Item* parent = NULL;
};

/*
* Add item 2 list
* info - значение, parent - вершина созданного элемента
*/
void push(Item **parent, int info){
	Item *pv = new Item;
	pv->info = info;
	pv->parent = *parent;
	*parent = pv;
}

/*
* Reverse enginering
*/
void reverse(Item** head_ref)
{
	Item* prev = NULL;
	Item* current = *head_ref;
	Item* next;
	while (current != NULL)
	{
		next = current->parent;
		current->parent = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void printList(Item *head)
{
	Item *temp = head;
	while (temp != NULL)
	{
		cout << temp->info << " ";
		temp = temp->parent;
	}
}

/*
* Search item from data
*/
Item* search(Item* head, int data)
{
	Item* newList = head;
	while (newList->parent != NULL)
	{
		if (newList->info == data)
		{
			return newList;
		}
		newList = newList->parent;
	}
	return newList;
}

void task4(){
	int N = 0;
	cout << "Введите число N: " << endl << "-> ";
	cin >> N;

	//pull to list
	cout << "Введите числа: " << endl << "-> ";
	int *mass = new int[N];
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		mass[i] = value;
	}

	Item *root = NULL;

	for (int i = N - 1; i >= 0; i--){
		int value = mass[i];
		push(&root, value);
	}

	Item *top = root;

	while (top != NULL){
		if (top->parent == NULL){
			break;
		}
		top = top->parent;
	}

	//reverse(&root);
	cout <<  "Вершина: " << top->info;
	
}

void task15(){
	Item *root1 = NULL;
	Item *root2 = NULL;

	int N = 10;

	//pull to list
	cout << "Введите 10 чисел: " << endl << "-> ";
	int *mass = new int[N];
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		mass[i] = value;
	}

	for (int i = 0; i < N; i++){
		if (mass[i] % 2){
			push(&root2, mass[i]);
		}
		else{
			push(&root1, mass[i]);
		}
	}

	//get start and end for root1
	Item *end1 = root1; // end
	Item *top1 = root1; // top

	while (top1 != NULL){
		if (top1->parent == NULL){
			break;
		}
		top1 = top1->parent;
	}
	printList(root1);
	cout << "P1_Top=" << top1->info << " P1_End=" << end1->info << endl;

	//get start and end for root2
	Item *end2 = root2; // end
	Item *top2 = root2; // top

	while (top2 != NULL){
		if (top2->parent == NULL){
			break;
		}
		top2 = top2->parent;
	}
	printList(root2);
	cout << "P2_Top=" << top2->info << " P2_End=" << end2->info << endl;
}


// Double linked list implementation
struct Node {
	int data;
	Node* next = NULL;
	Node* prev = NULL;
};

Node* head = NULL;
Node* last = NULL;
Node* current = NULL;

void insert(int data)
{
	Node* newList = NULL;
	if (head != NULL)
	{
		newList = new Node;
		newList->data = data;
		newList->next = NULL;
		newList->prev = current;
		current->next = newList;
		last = newList;
		current = newList;
	}
	else
	{
		newList = new Node;
		newList->data = data;
		head = newList;
		newList->next = NULL;
		newList->prev = NULL;
		current = newList;
		last = head;
	}
}

void show_list()
{
	struct Node* info;
	info = head;
	while (info)
	{
		cout << info->data << " ";
		info = info->next;
	}
	cout << "\n";
}

Node* search(int data)
{
	Node* newList = head;
	while (newList != last->next)
	{
		if (newList->data == data)
		{
			return newList;
		}
		newList = newList->next;
	}
	return newList;
}

void task45(){
	//pre init
	head = NULL;
	last = NULL;
	current = NULL;

	//pulling 2 list
	for (int i = 0; i < 10; i++){
		int x = rand() % 100;
		insert(x);
	}

	cout << "Original:" << endl;
	show_list();

	int N = 0;
	cout << "Введите элемент" << endl << "-> ";
	cin >> N;

	Node* node = search(N);


	//No changes ?
	if (node->data == head->data){
		cout << "Modded: " << endl;
		show_list();
		cout << "head: " << head->data << endl;
		cout << "last: " << last->data << endl;
		return;
	}

	node->prev->next = node->next;
	if (node->next){
		node->next->prev = node->prev;
	}

	node->prev = NULL;
	node->next = head;
	head->prev = node;
	head = node;

	while(last->next != NULL){
		last = last->next;
	}

	cout << "Modded: " << endl;
	show_list();
	cout << "head: " << head->data << endl;
	cout << "last: " << last->data << endl;
}

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	bool run = true;

	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера -->" << endl;
		cout << "4 15 45";
		cout << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 4:
			task4();
			break;
		case 15:
			task15();
			break;
		case 45:
			task45();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}