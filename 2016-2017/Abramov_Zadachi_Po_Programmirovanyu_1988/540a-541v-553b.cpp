/**
*
* Developed: D3v3l0p3d_0n3
* Copyright (C) 2016 DevelopedInside
*
**/
#include<iostream>
#include<ctime>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

/**
*
* Struct Utils
*
*/
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

void task540a(){
	int N = 0;
	cout << "Введите N" << endl << "-> ";
	cin >> N;
	cout << "Введите последовательность" << endl << "-> ";

	// Create root item
	Item *top = NULL;

	bool triggered = false;
	//pull to list
	for (int i = 0; i < N * 2; i++){
		int value = 0;
		cin >> value;
		push(&top, value);
	}

	Item *item = top;
	Item *x = top;

	//search X item
	for (int i = 0; i < N; i++){
		if (x->parent == NULL){
			break;
		}
		x = x->parent;
	}

	while (item != NULL && x != NULL){
		int ai = -x->info;
		Item* next = item->parent;
		if (next == NULL){
			break;
		}
		cout << "X=" << item->info << endl;
		cout << "Xn=" << ai << endl;
		if (item->info != ai){
			triggered = true;
			break;
		}
		item = next;
		x = x->parent;
	}

	if (triggered){
		cout << "No!";
		return;
	}

	cout << "Yep!";
}

void task541v(){
	int N = 0;
	cout << "Введите длину массива" << endl << "-> ";
	cin >> N;
	cout << "Введите числа" << endl << "-> ";

	// Create root item
	Item *top = NULL;

	//pull items 2 list
	for (int i = 0; i < N; i++){
		int value = 0;
		cin >> value;
		push(&top, value);
	}
	reverse(&top);

	//create root item for result
	Item *result = NULL;

	// get minus
	Item *item = top;
	while (item != NULL){
		if (item->info < 0){
			push(&result, item->info);
		}

		Item *next = item->parent;
		if (next == NULL){
			break;
		}
		item = next;
	}

	// get plus
	Item *itemPlus = top;
	reverse(&itemPlus);

	while (itemPlus != NULL){
		if (itemPlus->info > 0){
			push(&result, itemPlus->info);
		}

		Item *next = itemPlus->parent;
		if (next == NULL){
			break;
		}
		itemPlus = next;
	}

	reverse(&result); // reverse result

	printList(result);
}

void task553b(){
	//532: n << 1500
	int n = 0;
	cout << "Введите n:" << endl << "->";
	cin >> n;
	if (n < 1500){
		Item* root = NULL;

		for (int i = 0; i < n; i++){
			int v = 0;
			cin >> v;
			push(&root, v);
		}

		bool triggered = false;
		Item *item = root;
		while (item != NULL){
			Item* next = item->parent;
			if (next == NULL){
				break;
			}

			if (item->info <= next->info){
				triggered = true;
				break;
			}
			item = next;
		}

		if (triggered){
			cout << "Reversing..." << endl;
			//reverse(&root);
			printList(root);
			return;
		}
		cout << "No changes..." << endl;
		reverse(&root);
		printList(root);
	}
	else {
		cout << "Nope. Max N = 1500";
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	bool run = true;
	while (run){
		int i = 0;
		cout << "<!-- Введите номер задания --!>" << endl << "<!-- Доступные номера: " << 540 << " " << 541 << " " << 553 << " -->" << endl << "<!-- 0 - Выход -->" << endl;
		cout << "-> ";
		cin >> i;

		if (i == 0){
			cout << endl << "Exit!" << endl;
			run = false;
			return 0;
		}

		switch (i){
		case 540:
			task540a();
			break;
		case 541:
			task541v();
			break;
		case 553:
			task553b();
			break;
		default:
			cout << "Неопределенный номер задания. " << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}