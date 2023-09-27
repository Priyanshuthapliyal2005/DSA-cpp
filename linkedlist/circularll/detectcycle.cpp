#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main() {
    // Create a sample linked list with a cycle.
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Create a cycle here by connecting node4 to node2.

    // Create an instance of the Solution class.
    Solution solution;

    // Use the hasCycle function to check for a cycle in the linked list.
    bool hasCycle = solution.hasCycle(head);

    // Output the result.
    if (hasCycle) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Clean up the dynamically allocated memory.
    delete head;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
