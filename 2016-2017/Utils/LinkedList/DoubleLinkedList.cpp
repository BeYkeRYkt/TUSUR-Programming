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

// Double linked list implementation
struct Node {
	int data; //Значение
	Node* next = NULL; // Ссылка на следующий Node
	Node* prev = NULL; // Ссылка на предыдущий Node
};

// public params
Node* head = NULL;
Node* last = NULL;
Node* current = NULL;

/*
* Добавление в массив
* data - значение (int)
*/
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

/*
* Показать список
*/
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

/*
* Поиск Node по значению
* data - значение
*/
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
