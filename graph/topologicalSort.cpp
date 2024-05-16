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

vector<int> topologicalSortbfs(vector<vector<int>> &edges, int V, int e){
    unordered_map<int,list<int>>adj;

    //create adj list 
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }

    //indegree array
    vector<int>indegree(V,0);
    for(auto i : adj){
        for (auto j : i.second){
            indegree[j]++;
        }
    }

    //queue for bfs
    queue<int>q;

    //0 indegree wale ko push kr do 
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //abb baki element ko push kreneg 
    vector<int>ans;
    for(int i=0;i<V;i++){
        if(q.empty()){
            return {};
        }
        int node=q.front();
        q.pop();

        ans.push_back(node);

        for(auto i :adj[node]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
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
    // vector<int> sorted_order = topologicalSortbfs(edges, V, e);

    // Outputting the sorted order
    cout << "Topological Sort Order: ";
    for(int node : sorted_order){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
