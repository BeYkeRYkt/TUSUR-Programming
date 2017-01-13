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