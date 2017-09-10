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

/*
* Кто захочет - тот поймет.
*/

using namespace std;

//Single linked list
struct Item {
	int info;
	Item* next = NULL;
};

/*
* Add item 2 list
* info - значение, next - вершина созданного элемента
*/
void push(Item **next, int info){
	Item *pv = new Item;
	pv->info = info;
	pv->next = *next;
	*next = pv;
}

/*
* Reverse engineering
* (Лево -> Направо) -> (Право -> Налево)
*/
void reverse(Item** head_ref)
{
	Item* prev = NULL;
	Item* current = *head_ref;
	Item* next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/*
* Вывод списка 
* head - вершина
*/
void printList(Item *head)
{
	Item *temp = head;
	while (temp != NULL)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
}

/*
* Search item from data
* head - вершина, data - значение
*/
Item* search(Item* head, int data)
{
	Item* newList = head;
	while (newList->next != NULL)
	{
		if (newList->info == data)
		{
			return newList;
		}
		newList = newList->next;
	}
	return newList;
}
