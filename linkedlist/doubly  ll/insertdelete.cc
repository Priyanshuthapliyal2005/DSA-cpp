#include <iostream>
#include <map> // Include map for using std::map
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        } else if (this->prev != NULL) {
            delete prev;
            prev = NULL;
        }
        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
    } else {
        // Non-empty list
        // Assume that element is present in the linked list
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next; // Change to next for doubly linked list
            if (curr == tail) {
                cout << "Element " << element << " not found in the list." << endl;
                return;
            }
        }
        // Element found, curr is representing the element's node
        Node* temp = new Node(d);
        temp->prev = curr;
        temp->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = temp;
        }
        curr->next = temp;
    }
}


void deleteNode(Node*& tail, int val) {
    // Empty linked list
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    } else {
        Node* curr = tail;
        while (curr != NULL && curr->data != val) {
            curr = curr->next; // Change to next for doubly linked list
        }
        if (curr == NULL) {
            cout << "\nElement " << val << " not found in the list." << endl;
            return;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        } else {
            tail = curr->next;
        }

        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }

        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}


// Function to print the doubly linked list
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = tail;
    while (current != NULL) {
        cout << current->data << " <-> ";
        current = current->next;
    }

    cout << "NULL" << endl << endl;
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
    cout << "\nDeleted node with data 5: ";
    print(tail);

    return 0;
}
