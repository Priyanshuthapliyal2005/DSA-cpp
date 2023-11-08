#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree()
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    node* root = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree();
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree();
    return root;
}

void iterativePostorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<node*> s;
    node* current = root;
    node* lastVisited = nullptr;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();

        // If the right subtree is not yet processed
        if (current->right != nullptr && current->right != lastVisited)
        {
            current = current->right;
        }
        else
        {
            cout << current->data << " ";
            lastVisited = current;
            s.pop();
            current = nullptr; // Set current to nullptr to avoid revisiting nodes
        }
    }
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = buildtree();
    cout << "Iterative Inorder traversal result:" << endl;
    iterativePostorder(root);

    cout << "\nRecursive Inorder traversal result:" << endl;
    postorder(root);

    return 0;
}
