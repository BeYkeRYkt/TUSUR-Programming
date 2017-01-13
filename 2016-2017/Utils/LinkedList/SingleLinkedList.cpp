/**********************************************************************************************************\
* Copyright (C) 2k17 DevelopedInside
* Created by
 ____       __              __   ___       __              __       __              __              __     
/\  _`\   /'__`\          /'__`\/\_ \    /'__`\          /'__`\    /\ \           /'__`\          /'__`\   
\ \ \/\ \/\_\L\ \  __  __/\_\L\ \//\ \  /\ \/\ \  _____ /\_\L\ \   \_\ \         /\ \/\ \    ___ /\_\L\ \  
 \ \ \ \ \/_/_\_<_/\ \/\ \/_/_\_<_\ \ \ \ \ \ \ \/\ '__`\/_/_\_<_  /'_` \        \ \ \ \ \ /' _ `\/_/_\_<_ 
  \ \ \_\ \/\ \L\ \ \ \_/ |/\ \L\ \\_\ \_\ \ \_\ \ \ \L\ \/\ \L\ \/\ \L\ \        \ \ \_\ \/\ \/\ \/\ \L\ \
   \ \____/\ \____/\ \___/ \ \____//\____\\ \____/\ \ ,__/\ \____/\ \___,_\        \ \____/\ \_\ \_\ \____/
    \/___/  \/___/  \/__/   \/___/ \/____/ \/___/  \ \ \/  \/___/  \/__,_ /  _______\/___/  \/_/\/_/\/___/ 
                                                    \ \_\                   /\______\                      
                                                     \/_/                   \/______/                      
\***********************************************************************************************************/

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