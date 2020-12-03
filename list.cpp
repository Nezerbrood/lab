#include "list.h"

void List::push_back(int val)
{
	Node* cur = new Node;
	cur->value = val;
	cur->left = tail;
	cur->right = NULL;
	if (tail == NULL) {
		size = 1;
		tail = cur;
		head = cur;
	}
	else {
		size++;
		tail->right = cur;
		tail = cur;
	}
}

void List::push_front(int val){
	Node* cur = new Node;
	cur->value = val;
	cur->left = NULL;
	cur ->right = head;
	if (head == NULL) {
		size = 1;
		tail = cur;
		head = cur;
	}
	else {
		head->left = cur;
		head = cur;
		size++;
	}
}

void List::push_in(int indx, int val)
{
	if (indx >= size) {
		push_back(val);
		return;
	}
	else {
		Node* tmp = head;
		for (int i = 0; i < indx; i++) {
				tmp = tmp->right;
		}
		if (tmp == head) {
			push_front(val);
			return;
		}
		else if (tmp == tail) {
			push_back(val);
			return;
		}
		else {
			Node* cur = new Node;
			tmp->left->right = cur;
			cur->left = tmp->left;
			tmp->left = cur;
			cur->right = tmp;
			cur->value = val;
			size++;
		}
	}
}

void List::insert_after(Node* pointer, int val)
{
	Node* cur = new Node;
	cur->right = pointer->right;
	pointer->right = cur;
	cur->left = pointer;
	size++;
}

void List::insert_afore(Node* pointer, int val)
{
	Node* cur = new Node;
	cur->left = pointer;
	cur->right = pointer->right;
	cur->value = val;
	pointer->right = cur;
	size++;
}

void List::remove(int val)
{
	Node* tmp = head;
	if (!tmp) { return; }
	while (true) {
		if (tmp->value == val) {
			if (tmp == head) {
				pop_front();
				break;
			} else if (tmp == tail) {
				pop_back();
				break;
			} else {
				tmp->left->right = tmp->right;
				tmp->right->left = tmp->left;
				delete tmp;
				size--;
				break;
			}
		}
		else {
			if (!tmp->right) {
				tmp = tmp->right;
			}
			else {
				return;
			}
		}
	}
}

void List::erase(int indx){
	Node* cur = head;
	for (int i = 0; i < indx; i++) {
		cur = cur->right;
	}
	if (cur == head) {
		pop_front();
		return;
	}
	else if (cur == tail) {
		pop_back();
		return;
	}
	cur->left->right = cur->right;
	cur->right->left = cur->left;
	size--;
	delete cur;

}

void List::pop_front()
{
	if (head == tail) {
		size--;
		delete head;
		head = NULL;
		tail = NULL;

	}
	else {
		head->right->left = NULL;
		size--;
		Node* tmp = head->right;
		delete head;
		head = tmp;
	}
}

void List::pop_back()
{
	if (head == tail) {
		delete head;
		head = NULL;
		tail = NULL;
		size = 0;
	}
	else {
		tail->left->right = NULL;
		size--;
		Node* tmp = tail->left;
		delete tail;
		tail = tmp;
	}
}

void List::remove_after(Node* pointer)
{
	Node* tmp = pointer->right;
	if (tmp == tail) {
		pop_back();
		return;
	}
	pointer->right = tmp->right;
	tmp->right->left = pointer;
	size--;
	delete tmp;
}

void List::remove_afore(Node* pointer)
{
	Node* tmp = pointer->left;
	if (tmp == head) {
		pop_front();
		return;
	}
	tmp->left->right = pointer;
	pointer->left = tmp->left;
	size--;
	delete tmp;
}

void List::print()
{
	Node* tmp = head;
	for (int i = 0; i < size; i++) {
		std::cout << tmp->value << ' ';
		tmp = tmp->right;
	}
}

void List::destroy()
{
	while (head!= NULL) {
		pop_back();
	}
}

bool List::is_empty()
{
	if (!head) { return true; }
	return false;
}

int List::search(int val)
{
	Node* tmp = head;
	for (int i = 0; i < size; i++) {
		if (val == tmp->value) {
			return i;
		}
	}
	return - 1;
}
