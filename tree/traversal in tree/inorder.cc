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
    if (data == -1)
    {
        return nullptr;
    }
    node *root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree();
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree();
    return root;
}

void iterativeInorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<node *> s;
    node *current = root;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

void inorder(node* root){
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main()
{
    node *root = buildtree();
    cout << "Iterative Inorder traversal result:" << endl;
    iterativeInorder(root);

    cout << "\nRecursive Inorder traversal result:" << endl;
    inorder(root);

    return 0;
}
