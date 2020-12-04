#pragma once
#include <malloc.h>
#include <iostream>
class Node
{
public:
	int value;
	Node* left;
	Node* right;
};
class List
{
	void swap(Node* first, Node* second*);
public:
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
	/*List() {
		head = NULL;
		tail = NULL;
	}*/
	void push_back(int val);
	void push_front(int val);
	void push_in(int indx, int val);
	void insert_after(Node* pointer,int val);
	void insert_afore(Node* pointer, int val);
	void remove(int val);
	void erase(int index);
	void pop_front();
	void pop_back();
	void remove_after(Node* pointer);
	void remove_afore(Node* pointer);
	void print();
	void destroy();
	bool is_empty();
	int search(int val);
	int get(int index);
	void sortB();
};

// 1. возможность подключать как библиотеку
// храним int
// 2. уметь создавать список

// функции:

// 3. добавлять элементы в список
// 3.1. в начало // push_front
// 3.2. в конец // push_back
// 3.3. в произвольное место (по индексу, нумерация с нуля) // insert
// 3.10. "вставить после" (принимает Node)
// 3.11. "вставить перед" (принимает Node)

// 4. удалять элементы из списка
// 4.1. по значению // remove
// 4.2. по позиции // erase
// 4.3. из начала // pop_front
// 4.4. из конца // pop_back
// 4.10. "удалить после" (принимает Node)
// 4.11. "удалить перед" (принимает Node)

// обработка ошибок не нужна

// 5. количество эл-в в списке // size
// 5.1. bool -> пустой ли список bool empty()

// 6. возможность удалять весь список: освобождается вся память, занятая этим списком // destroy

// 7. поиск: в какой позиции находится нужный элемент -> возвр. позицию 0..size-1 // find
// 7.1. если не находит: -1 или size

// доп задание: функция сортировки связного списка
