#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> leftrotate(vector<int>&arr,int d){
    d=d%arr.size();
    int temp[d];
    int i=0;
    for(i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<arr.size();i++){
            arr[i-d]=arr[i];

    }
    for(int i=arr.size()-d;i<arr.size();i++){
            arr[i]=temp[i-(arr.size()-d)];

    }
    
    return arr;
}
int main(){
    vector<int>arr={2,4,9,7,5};
    vector<int>r;
    int d;
    cin>>d;

    int i;
    r=leftrotate(arr,d);
    for(i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}