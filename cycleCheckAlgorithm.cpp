#include <iostream>

struct ListNode {
    int _val;
    ListNode *_next;
    ListNode(const int &val) : _val(val), _next(nullptr) {} 
};

bool hasCycle(ListNode *head) {
    if (!head || !head->_next) {
        return false; 
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->_next) {
        slow = slow->_next;          
        fast = fast->_next->_next;   

        if (slow == fast) {          
            return true;
        }
    }

    return false; 
}

int main() {

    ListNode *head = new ListNode(1);
    head->_next = new ListNode(2);

    head->_next->_next = head->_next;

    if (hasCycle(head)) {
        std::cout << "The linked list has a cycle.\n";
    } else {
        std::cout << "The linked list does not have a cycle.\n";
    }

    return 0;
}