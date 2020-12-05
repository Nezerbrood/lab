#include "list.h"
#include <iostream>
int main() {
    List list;
    if (list.is_empty()) {
        list.push_back(1);
        if (!list.is_empty()) {
            std::cout << "test 1: successfully completed!" << '\n';
        }
        else {
            std::cout << "test 1: failed!" << '\n';
        }
    }
    list.push_back(2);
    list.push_back(3);
    if (list.get_size() == 3) {
        std::cout << "test 2: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 2: failed!" << '\n';
    }
    list.push_front(0);
    if (list.get(0) == 0) {
        std::cout << "test 3: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 3: failed!" << '\n';
    }
    // [0, 1, 2, 3]
    Node* _testNode = list.get_pointer(2); //_testNode = 2
    list.insert_afore(_testNode, 99);
    //[0, 1, 99, 2, 3]
    list.insert_after(_testNode, 88);
    //[0, 1, 99, 2, 88, 3]
    if (list.get(2) == 99 and list.get(4) == 88) {
        std::cout << "test 4: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 4: failed!" << '\n';
    }
    if (list.search(1000) == -1) {
        list.insert_after(_testNode, 1000);
        //[0, 1, 99, 2, 1000, 88, 3]
        if (list.search(1000) == 4) {
            std::cout << "test 5: successfully completed!" << '\n';
        }
        else {
            std::cout << "test 5: failed!" << '\n';
        }
    }
    else {
        std::cout << "test 5: failed!" << '\n';
    }
    list.remove(99);
    //[0, 1, 2, 1000, 88, 3]
    if (list.search(99) == -1) {
        std::cout << "test 6: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 6: failed!" << '\n';
    }
    list.erase(2);
    //[0, 1, 1000, 88, 3]
    if (list.get(2) == 1000) {
        std::cout << "test 7: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 7: failed!" << '\n';
    }
    list.pop_front();
    list.pop_back();
    //[1, 1000, 88]
    if (list.get(0) == 1 and list.get(list.get_size()-1)==88) {
        std::cout << "test 8: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 8: failed!" << '\n';
    }
    _testNode = list.get_pointer(1);
    list.remove_afore(_testNode);
    list.remove_after(_testNode);
    //[1000]
    if (list.get_size() == 1 and list.get(0) == 1000) {
        std::cout << "test 9: successfully completed!" << '\n';
    }
    else {
        std::cout << "test 9: failed!" << '\n';
    }
    list.push_back(77);
    list.push_back(55);
    list.push_back(14);
    list.push_back(109);
    list.push_back(3);
    //[1000, 77, 55, 14, 109, 3]
    list.sortB();
    //[3, 14, 55, 77, 109, 1000]
    if (
        list.get(0) == 3 and
        list.get(1) == 14 and
        list.get(2) == 55 and
        list.get(3) == 77 and
        list.get(4) == 109 and
        list.get(5) == 1000
        ) {
        std::cout << "test 10: successfully completed!" << '\n';
    }
    else
    {
        std::cout << "test 10: failed!" << '\n';
    }

}
