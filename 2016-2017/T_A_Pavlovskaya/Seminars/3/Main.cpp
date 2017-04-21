#include <iostream>
#include <Windows.h>
#include <string>

#include "Deque.h"

using namespace std;

int main(){
	try {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		bool run = true;

		Deque<double>* d = new Deque<double>();
		int element, value;

		while (run){
			int i = 0;
			cout << "<!-- Deque implementation -->" << endl;
			cout << "1. Добавить элемент в начало очереди" << endl;
			cout << "2. Добавить элемент в конце очереди" << endl;
			cout << "3. Удаление элемента в начале очереди" << endl;
			cout << "4. Удаление элемента в конце очереди" << endl;
			cout << "5. Показать элемент в начале очереди" << endl;
			cout << "6. Показать элемент в конце очереди" << endl;
			cout << "7. Показать список элементов" << endl;

			cout << "<!-- Error generator -->" << endl;
			cout << "8. Сгенерировать ошибку DequeRangeError()" << endl;
			cout << "9. Сгенерировать ошибку DequeNullPointerError()" << endl;

			cout << endl << "0. - Выход" << endl;
			cout << "-> ";
			cin >> i;
			cout << endl;

			switch (i){
			case 0:
				run = false;
				break;
			case 1:
				cout << "Введите элемент" << "-> " << endl;
				cin >> element;
				d->enqueueFirst(element);
				break;
			case 2:
				cout << "Введите элемент" << "-> " << endl;
				cin >> element;
				d->enqueueLast(element);
				break;
			case 3:
				try {
					value = d->dequeueFirst();
					cout << "Вы удалили: " << value << endl;
				}
				catch (DequeError& err){ err.ErrMsg(); }
				break;
			case 4:
				try {
					value = d->dequeueLast();
					cout << "Вы удалили: " << value << endl;
				}
				catch (DequeError& err){ err.ErrMsg(); }
				break;
			case 5:
				try{
					value = d->peekFirst();
					cout << "В начале очереди: " << value << endl;
				}
				catch (DequeError& err){ err.ErrMsg(); }
				break;
			case 6:
				try{
					value = d->peekLast();
					cout << "В конце очереди: " << value << endl;
				}
				catch (DequeError& err){ err.ErrMsg(); }
				break;
			case 7:
				cout << "Количество элементов: " << d->getQueueCount() << endl;
				d->showQueue();
				cout << endl;
				break;
			case 8:
				d->generateRangeError();
				break;
			case 9:
				d->generateNullError();
				break;
			default:
				cout << "Hotline miami: Wrong number" << endl;
				break;
			}
			cout << endl;
		}
	}
	catch (...) { cerr << "Epilogue: error of Main().\n"; }
	return 0;
}