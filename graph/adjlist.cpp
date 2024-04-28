// // #include<bits/stdc++.h>

// // using namespace std;


// // class Graph{
// // public:
// //     unordered_map<int,list<int>>adj;
// //     void addEdges(int u,int v ,bool direction){
// //         if(direction==1){
// //             //u se v ki taraf ek edge hai 
// //             //u->v
// //             adj[u].push_back(v);
// //         }else{
// //             //direction=0
// //             //u -- v
// //             //u -> v
// //             adj[u].push_back(v);
// //             //v -> u
// //             adj[v].push_back(u);

// //         }
// //         cout<<"Edge added"<<endl;
// //         printGraph();
// //         cout<<endl;
// //     }
// //     void printGraph(){
// //         for(auto i :adj){
// //             cout<<i.first<<"->";
// //             for(auto j:i.second){
// //                 cout<<j<<",";
// //             }
// //             cout<<"}"<<endl;
// //         }
// //     }
// // };




// // int main()
// // {
// //     Graph g;
// //     g.addEdges(0,1,0);
// //     g.addEdges(0,4,1);
// //     g.addEdges(1,2,1);
// //     g.addEdges(2,3,1);
// //     g.addEdges(2,4,1);
// //     g.addEdges(3,4,1);
// //     g.printGraph();

// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// const bool DIRECTED = true;
// const bool UNDIRECTED = false;

// class Graph {
// public:
//     unordered_map<int, list<int>> adj;

//     void addEdge(int u, int v, bool isDirected) {
//         adj[u].push_back(v);
//         if (!isDirected)
//             adj[v].push_back(u);
//     }

//     void printGraph() {
//         for (const auto& [vertex, neighbors] : adj) {
//             cout << vertex << "->{"; // Start of the output format
//             for (int neighbor : neighbors)
//                 cout << neighbor << ",";
//             cout << "}" << endl; // End of the output format
//         }
//     }
// };

// int main() {
//     Graph g;
//     g.addEdge(0, 1, UNDIRECTED);
//     g.addEdge(0, 4, DIRECTED);
//     g.addEdge(1, 2, DIRECTED);
//     g.addEdge(2, 3, DIRECTED);
//     g.addEdge(2, 4, DIRECTED);
//     g.addEdge(3, 4, DIRECTED);

//     g.printGraph();

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v,int wt, bool isDirected) {
        //directed=0 : undirected
        //directed=1 -> directed 

        if(isDirected==1){
            adjList[u].push_back(make_pair(v,wt));
        }else{
            //directed ==0
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        printGraph();
        cout<<endl;
    }

    void printGraph() {
        for (auto i:adjList){
            cout<< i.first<< ": {";
            for(pair<int,int> p :i.second){
                cout<<"{"<<p.first<<","<<p.second<<"},";

            }
            cout<<"}"<<endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0,1,5,0);
    g.addEdge(1,2,10,0);
    g.addEdge(1,3,20,0);
    g.addEdge(2,3,50,0);
    return 0;
}
