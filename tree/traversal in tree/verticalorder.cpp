#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printSpace(double n, Node* removed)
{
    for (; n > 0; n--) {
        cout << "\t";
    }
    if (removed == nullptr) {
        cout << " ";
    }
    else {
        cout << removed->data;
    }
}
 
int heightOfTree(Node* root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1+ max(heightOfTree(root->left),heightOfTree(root->right));
}

void printBinaryTree(Node* root)
{
    queue<Node*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int height = heightOfTree(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        Node* removed = treeLevel.front();
        treeLevel.pop();
        if (temp.empty()) {
            printSpace(numberOfElements
                           / pow(2, counter + 1),
                       removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                       removed);
        }
        if (removed == nullptr) {
            temp.push(nullptr);
            temp.push(nullptr);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            counter++;
        }
    }
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int> > > nodes;
        queue< pair<Node*, pair<int,int> > > q;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};



// { Driver Code Starts.
int main() {
    // Example input string for a single testcase
    // string s = "1 2 3 N N 4 6";
    string s = "1 2 3 4 5 6 7";

    // Construct the binary tree
    Node* root = buildTree(s);
    printBinaryTree(root);
    // Create an object of the Solution class
    Solution obj;

    // Find the vertical order traversal of the binary tree
    vector<int> res = obj.verticalOrder(root);

    // Print the result
    cout << "Vertical Order Traversal: ";
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}


  // } Driver Code Ends