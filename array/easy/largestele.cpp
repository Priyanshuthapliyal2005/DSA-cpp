#include<iostream>
#include<vector>
using namespace std;
int largesteleinarr(vector<int>&arr,int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}
int main(){
    vector<int>arr={2,4,9,7,5};
    int n=arr.size();
    int result=largesteleinarr(arr,n);
    cout<<" largest element in the array is "<<result<<endl;
    return 0;
}