#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&v){
    for(int i=1;i<v.size();i++){
        int j=i;
        while(v[j-1]>v[j] && j>0){
            swap(v[j-1],v[j]);
            j--;
        }
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
    cout<<"insertion sort sorted array: ";
    for(auto i:v){
        cout<<i<<" ";
    }
}