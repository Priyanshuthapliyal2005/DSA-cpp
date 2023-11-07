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

node *buildtree(node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void reverselevelordertraversal(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    stack<node *> s;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
    }
}


int main()
{
    node *root = nullptr;
    root = buildtree(root);
    reverselevelordertraversal(root);
    return 0;
}
