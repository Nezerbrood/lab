#include "list.h"

void List::push_back(int val)
{
	create_node(tail, NULL, val);
}

void List::push_front(int val){
	create_node(NULL, head, val);
}

void List::push_in(int indx, int val)
{
	if (indx >= size) {
		push_back(val);
		return;
	} else {
		Node* ptr = get_pointer(indx);
		create_node(ptr->left, ptr, val);
	}
}

void List::insert_after(Node* pointer, int val)
{
	create_node(pointer, pointer->right, val);
}

void List::insert_afore(Node* pointer, int val)
{
	create_node(pointer->left, pointer, val);
}

void List::remove(int val)
{
	int search_result = search(val);
	if (search_result == -1) { return; }
	Node* ptr = get_pointer(search_result);
	erase_p(ptr);
}

void List::erase(int indx){
	Node* ptr = get_pointer(indx);
	erase_p(ptr);
}

void List::pop_front()
{
	erase_p(head);
}

void List::pop_back()
{
	erase_p(tail);
}

void List::remove_after(Node* pointer)
{
	erase_p(pointer->right);
}

void List::remove_afore(Node* pointer)
{
	erase_p(pointer->left);
}

void List::print()
{
	Node* tmp = head;
	for (int i = 0; i < size; i++) {
		std::cout << tmp->value << ' ';
		tmp = tmp->right;
	}
	std::cout << '\n';
}

void List::clear()
{
	while (head!= NULL) {
		erase_p(tail);
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
		tmp = tmp->right;
	}
	return - 1;
}

int List::get(int index)
{
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		cur = cur->right;
	}
	return cur->value;
}

void List::sortB()
{
	if (size == 1) { return; }
	Node* cur_main = head->right;
	do {
		Node* cur = cur_main;
		Node* tmp = cur->left;
		while (cur->value < tmp->value){
			if (tmp != head) {
				swap(cur, tmp);
				cur = tmp;
				tmp = cur->left;
			}
			else{
				swap(cur, tmp);
				break;
			}
		}
		cur_main = cur_main->right;
	} while (cur_main != NULL);
	if (tail->value < tail->left->value) { swap(tail, tail->left); }
}



void List::swap(Node* first, Node* second)
{
	int tmp;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void List::create_node(Node* p_left, Node* p_right, int val)
{
	Node* cur = new Node;
	cur->left = p_left;
	cur->right = p_right;
	cur->value = val;
	if (p_right == NULL) {
		tail = cur;
	}
	else {
		p_right->left = cur;
	}
	if (p_left == NULL) {
		head = cur;
	}
	else {
		p_left->right = cur;
	}
	size++;

}

void List::erase_p(Node* pointer)
{
	Node* l = pointer->left;
	Node* r = pointer->right;
	if (l != NULL) {
		l->right = r;
	}
	else {
		head = r;
	}
	if (r != NULL) {
		r->left = l;
	}
	else {
		tail = l;
	}
	delete pointer;
	size--;
}

Node* List::get_pointer(int index)
{
	Node* tmp = head;
	for (int i = 0; i < index; i++) {
		tmp = tmp->right;
	}
	return tmp;
}


