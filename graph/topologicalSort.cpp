#include<bits/stdc++.h>

using namespace std;

// Function to perform Depth First Search for Topological Sort
void topoSortDFS(int node, vector<bool> &vis, stack<int> &s, unordered_map<int,list<int>>&adj){
    vis[node] = true;
    for(auto nbr : adj[node]){
        if(!vis[nbr]){
            topoSortDFS(nbr, vis, s, adj);
        }
    }
    s.push(node);
}

// Function to perform topological sort on a directed graph
vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e){
    // Map to store adjacency list of the graph
    unordered_map<int, list<int>> adj;
    stack<int> s;

    // Creating adjacency list from given edges
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    // Array to keep track of visited nodes
    vector<bool> vis(V, false);

    // Performing DFS for each unvisited node
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            topoSortDFS(i, vis, s, adj);
        }
    }

    // Storing the result of topological sort
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    // Example: Creating a graph and calling topological sort function

    // Number of vertices
    int V = 6;

    // Number of edges
    int e = 6;

    // Example edges
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    // Performing topological sort
    vector<int> sorted_order = topologicalSort(edges, V, e);

    // Outputting the sorted order
    cout << "Topological Sort Order: ";
    for(int node : sorted_order){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
