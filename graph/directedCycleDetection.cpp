#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdges(T u, T v, int wt, bool direction)
    {
        if (direction)
        {
            adjList[u].push_back({v, wt});
        }
        else
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        cout << "Print adj List: " << endl;
        printGraph();
        cout << endl;
    }

    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " :{";
            for (auto neighbour : i.second)
            {
                cout << "{ " << neighbour.first << "," << neighbour.second << "},";
            }
            cout << "}" << endl;
        }
    }

    bool checkCycleDFS(T node, unordered_map<T, bool> &visited, unordered_map<T, bool> &recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (auto nbr : adjList[node])
        {
            T neighbour = nbr.first;
            if (!visited[neighbour])
            {
                if (checkCycleDFS(neighbour, visited, recStack))
                    return true;
            }
            else if (recStack[neighbour])
            {
                // Cycle detected
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }
    

    //find cycle using bfs

    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent =q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode,node});
                }else if(parent !=adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycleBfs(int V,vector<int> adj[])
    {
        int vis[V]=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))return true;
            }
        }   
        return false;
    }
};

int main()
{
    Graph<int> g;
    int n;
    cout << "Enter the number of nodes in the graph: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges in the graph: " << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        bool direction;
        cin >> u >> v >> wt >> direction;
        g.addEdges(u, v, wt, direction);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> recStack;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && g.checkCycleDFS(i, visited, recStack))
        {
            cout << "Cycle present in graph." << endl;
        }
        else
        {
            cout << "Cycle not present in graph. " << endl;
        }
    }
    return 0;
}