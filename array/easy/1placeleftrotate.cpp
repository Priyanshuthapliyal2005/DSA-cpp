#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> leftrotate(vector<int>&arr){
    int temp=arr[0];
    int i=0;
    for(i=0;i<arr.size();i++){
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;
    return arr;
}
int main(){
    vector<int>arr={2,4,9,7,5};
    vector<int>r;
    int i;
    r=leftrotate(arr);
    for(i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}