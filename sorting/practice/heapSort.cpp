#include<bits/stdc++.h>
using namespace std;


void minheapSort(vector<int> &v){
    priority_queue<int,vector<int>,greater<int>>minHeap{v.begin(),v.end()};
    int i=0;
    while(!minHeap.empty()){
        v[i++]=minHeap.top();
        minHeap.pop();
    }
}

void maxHeapSort(vector<int>&v){
    priority_queue<int>pq{v.begin(),v.end()};
    int i=0;
    while(!pq.empty()){
        v[i++]=pq.top();
        pq.pop();
    }
}

int main(){
    vector<int>v{5,4,3,2,1};
    cout<<"Original array: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"min Heap sort sorted array: ";
    minheapSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }

    cout<<endl;
    
    cout<<"max heap sort sorted array: ";
    maxHeapSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }
}