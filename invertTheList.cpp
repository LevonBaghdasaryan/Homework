#include <iostream>

struct ListNode {
    int _data;
    ListNode *_next;
    ListNode(const int &data) : _data(data), _next(nullptr) {}
};

ListNode* reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = nullptr;

    while(current != nullptr) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(ListNode *head) {
    while(head != nullptr) {
        std::cout << head->_data << " ";
        head = head->_next;
    }
    std::cout << std::endl;
}

int main() {

    ListNode *head = new ListNode(10);
    head->_next = new ListNode(20);
    head->_next->_next = new ListNode(30);
    head->_next->_next->_next = new ListNode(40);

    std::cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    std::cout << "Reversed List: ";
    printList(head);

    return 0;
}