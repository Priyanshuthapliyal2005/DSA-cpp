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
    node *root = new node(data);
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

void iterativePreorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {
        node *current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right != nullptr)
        {
            s.push(current->right);
        }
        if (current->left != nullptr)
        {
            s.push(current->left);
        }
    }
}


void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node *root = buildtree();
    cout << "Iterative Preorder traversal result:" << endl;
    iterativePreorder(root);

    cout << "\nRecursive Preorder traversal result:" << endl;
    preorder(root);

    return 0;
}
