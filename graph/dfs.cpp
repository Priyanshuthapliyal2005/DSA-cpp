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

    // void dfs(T src,unordered_map<T,bool> vis){
    //     //adjacent list pdi hai
    //     //visited
        
    //     stack<T>st;

    //     //initial state
    //     st.push(src);

    //     vis[src]=true;

    //     while(!st.empty())
    //     {
    //         T TopNode =st.top();
    //         cout<<TopNode<<" ";
    //         st.pop();

    //         //go to nbr
    //         for(auto nbr: adjList[TopNode]){
    //             T nbrData=nbr.first;
                
    //             if(!vis[nbrData]){
    //                 st.push(nbrData);
    //                 vis[nbrData]=true;
    //             }
    //         }
    //     }
    // }


    void dfs(T src,unordered_map<T,bool> &vis){
        vis[src]=true;

        cout<< src<< " ";

        for(auto nbr: adjList[src]){
            T nbrData=nbr.first;
            if(!vis[nbrData]){
                dfs(nbrData,vis);
            }
        }
    }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, 0, 1);
    g.addEdge(1, 2, 10, 1);
    g.addEdge(2, 3, 20, 1);
    g.addEdge(2, 4, 50, 1);
    g.addEdge(3, 4, 50, 1);
    g.addEdge(4,5,30,1);


    // // Additional disconnected component
    // g.addEdge(4, 5, 30, 1);
    // g.addEdge(5, 6, 40, 1);

    unordered_map<int, bool> vis;
    // g.dfs(0,vis);

    for (int node = 0; node <= 5; node++) {
        if (!vis[node]) {
            cout<<endl;
            g.dfs(node, vis);
        }
    }

    return 0;
}
