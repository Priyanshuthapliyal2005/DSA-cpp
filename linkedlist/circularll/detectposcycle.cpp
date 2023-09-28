#include <iostream>
// Floyd's cycle detection algorithm
// Definition for singly-linked list.
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getPositionOfCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        if (!slow || !slow->next) {
            return -1; // No cycle if there are less than two nodes.
        }
        
        int position = 0;
        bool cycleDetected = false;

        do {
            slow = slow->next;
            fast = fast->next->next;
            position++;
        } while (fast && fast->next && slow != fast);  

        if (!fast || !fast->next) {
            return -1; // No cycle if fast reaches the end of the list.
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return position; // Return the position where the cycle starts.
    }
    void print(ListNode* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    ListNode* current = head->next;
    do {
        cout << current->val << " -> ";
        current = current->next;
    } while (current != head->next);

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
    solution.print(head);
    // Use the getPositionOfCycle function to get the position of the cycle in the linked list.
    int position = solution.getPositionOfCycle(head);

    if (position != -1) {
        cout << "Cycle starts at position: " << position << endl;
    } else {
        cout << "No cycle found." << endl;
    }
    // Clean up the dynamically allocated memory.
    delete head;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
