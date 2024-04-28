#include<bits/stdc++.h>
using namespace std;



void printArray(vector<int>v){
    cout<<"insertion sort sorted array: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}



void insertionSort(vector<int>&v){
    for(int i=1;i<v.size();i++){
        int curr=v[i];
        int j=i-1;
        while(v[j]>curr && j>=0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=curr;
        printArray(v);
    }
}



int main(){
    vector<int>v{5,4,3,2,1};
    cout<<"Original array: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    insertionSort(v);
}