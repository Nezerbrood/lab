
#include "list.h"
#include <iostream>
int main() {
    List list1;
    List list2;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(4);
    list1.push_back(5);
    list1.push_in(2, 3);
    list1.remove(1);
    list1.remove(2);
    Node* testnode = list1.head->right;
    list1.remove_afore(list1.tail);
    list1.print();
    list1.destroy();
}
