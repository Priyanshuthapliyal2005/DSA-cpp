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

    void bfs(T src)
    {
        unordered_map<T, bool> vis;
        queue<T> q;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for (auto neighbour : adjList[node])
            {
                if (!vis[neighbour.first])
                {
                    q.push(neighbour.first);
                    vis[neighbour.first] = true;
                }
            }
        }
    }

    // Define your dfs function here
    void dfs(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto i : adjList[src])
        {
            if (!visited[i.first])
                dfs(i.first, visited);
        }
    }

    bool checkCycleUndirectedBFS(T src)
    {
        queue<T> q;
        unordered_map<T, bool> vis;
        unordered_map<T, T> parent;

        // Initial state
        q.push(src);
        vis[src] = true;
        parent[src] = src;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode])
            {
                if (!vis[nbr.first])
                {
                    vis[nbr.first] = true;
                    q.push(nbr.first);
                    parent[nbr.first] = frontNode;
                }
                else if (nbr.first != parent[frontNode])
                {
                    // If the neighbor is visited but not the parent, there's a cycle
                    return true;
                }
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
    int src;
    cout << "Enter source node for BFS: ";
    cin >> src;

    cout << "BFS traversal: ";
    g.bfs(src);
    cout << endl;

    unordered_map<int, bool> visited_dfs;
    cout << "Enter source node for DFS: ";
    cin >> src;
    cout << "DFS traversal: ";
    g.dfs(src, visited_dfs);
    cout << endl;

    if (g.checkCycleUndirectedBFS(src))
    {
        cout << "Cycle present in graph." << endl;
    }
    else
    {
        cout << "Cycle not present in graph. " << endl;
    }
    return 0;
}
