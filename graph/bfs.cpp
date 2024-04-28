#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Graph {
public:
    unordered_map<T, list<pair<T,int>>> adjList;

    void addEdge(T u, T v,int wt, bool isDirected) {
        //directed=0 : undirected
        //directed=1 -> directed 

        if(isDirected==1){
            adjList[u].push_back(make_pair(v,wt));
        }else{
            //directed ==0
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        cout<<"Print adj List: "<<endl;
        printGraph();
        cout<<endl;
    }

    void printGraph() {
        for (auto i:adjList){
            cout<< i.first<< ": {";
            for(pair<T,T> p :i.second){
                cout<<"{"<<p.first<<","<<p.second<<"},";

            }
            cout<<"}"<<endl;
        }
    }

    void bfs(T src,unordered_map<T,bool>vis){
        //adjacent list pdi hai
        //visited
        
        queue<T>q;

        //initial state
        q.push(src);

        vis[src]=true;

        while(!q.empty())
        {
            T frontNode =q.front();
            cout<<frontNode<<" ";
            q.pop();

            //go to nbr
            for(auto nbr: adjList[frontNode]){
                T nbrData=nbr.first;
                
                if(!vis[nbrData]){
                    q.push(nbrData);
                    vis[nbrData]=true;
                }
            }
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 0, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(1, 3, 20, 1);
    g.addEdge(2, 3, 50, 1);

    // Additional disconnected component
    g.addEdge(4, 5, 30, 1);
    g.addEdge(5, 6, 40, 1);

    unordered_map<int, bool> vis;

    for (int node = 0; node <= 6; node++) {
        if (!vis[node]) {
            cout<<endl;
            g.bfs(node, vis);
        }
    }

    return 0;
}
