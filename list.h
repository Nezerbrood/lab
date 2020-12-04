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

// 1. ����������� ���������� ��� ����������
// ������ int
// 2. ����� ��������� ������

// �������:

// 3. ��������� �������� � ������
// 3.1. � ������ // push_front
// 3.2. � ����� // push_back
// 3.3. � ������������ ����� (�� �������, ��������� � ����) // insert
// 3.10. "�������� �����" (��������� Node)
// 3.11. "�������� �����" (��������� Node)

// 4. ������� �������� �� ������
// 4.1. �� �������� // remove
// 4.2. �� ������� // erase
// 4.3. �� ������ // pop_front
// 4.4. �� ����� // pop_back
// 4.10. "������� �����" (��������� Node)
// 4.11. "������� �����" (��������� Node)

// ��������� ������ �� �����

// 5. ���������� ��-� � ������ // size
// 5.1. bool -> ������ �� ������ bool empty()

// 6. ����������� ������� ���� ������: ������������� ��� ������, ������� ���� ������� // destroy

// 7. �����: � ����� ������� ��������� ������ ������� -> �����. ������� 0..size-1 // find
// 7.1. ���� �� �������: -1 ��� size

// ��� �������: ������� ���������� �������� ������
