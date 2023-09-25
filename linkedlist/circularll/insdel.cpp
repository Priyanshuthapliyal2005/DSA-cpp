#include <iostream>
#include <map> // Include map for using std::map
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    } else {
        // Non-empty list
        // Assume that element is present in the linked list
        Node* curr = tail->next;
        while (curr->data != element) {
            curr = curr->next;
            if (curr == tail->next) {
                cout << "Element " << element << " not found in the list." << endl;
                return;
            }
        }
        // Element found, curr is representing the element's node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node*& tail, int val) {
    // Empty linked list
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    } else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != val) {
            prev = curr;
            curr = curr->next;
            if (curr == tail->next) {
                cout << "Element " << val << " not found in the list." << endl;
                return;
            }
        }
        prev->next = curr->next;

        // If there is only one node in the linked list
        if (curr == tail) {
            tail = NULL;
        } else if (curr == tail->next) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* tail) {
    // Empty list or single-node list
    if (tail == NULL || tail->next == tail) {
        return true;
    }

    Node* temp = tail->next;
    while (temp != tail) {
        if (temp == NULL) {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

bool detectLoop(Node* head) {
    if (head == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
}

// Function to print the linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = tail->next;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != tail->next);

    cout << "Tail" << endl<<endl;

}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    cout << "Inserted 3 after 5: ";
    print(tail);

    insertNode(tail, 3, 5);
    cout << "Inserted 5 after 3: ";
    print(tail);

    insertNode(tail, 5, 7);
    cout << "Inserted 7 after 5: ";
    print(tail);

    insertNode(tail, 7, 9);
    cout << "Inserted 9 after 7: ";
    print(tail);

    insertNode(tail, 5, 6);
    cout << "Inserted 6 after 5: ";
    print(tail);

    insertNode(tail, 9, 10);
    cout << "Inserted 10 after 9: ";
    print(tail);

    insertNode(tail, 3, 4);
    cout << "Inserted 4 after 3: ";
    print(tail);

    deleteNode(tail, 5);
    cout << "Deleted node with data 5: ";
    print(tail);

    if (isCircularList(tail)) {
        cout << "Linked List is Circular in nature" << endl;
    } else {
        cout << "Linked List is not Circular" << endl;
    }

    return 0;
}
