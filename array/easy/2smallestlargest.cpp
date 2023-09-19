#include<iostream>
#include<vector>
using namespace std;
int seclargest(vector<int>&arr,int n){
    int largest=arr[0];
    int seclargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            seclargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest&&arr[i]>seclargest){
            seclargest=arr[i];
        }
    }
    return seclargest;
}

int secsmallest(vector<int>&arr,int n){
    int smallest=arr[0];
    int secsmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            secsmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]!=smallest&&arr[i]<secsmallest){
            secsmallest=arr[i];
        }
    }
    return secsmallest;
}

int main(){
    vector<int>arr={2,4,9,7,5};
    int n=arr.size();
    int result=seclargest(arr,n);
    cout<<" second largest element in the array is "<<result<<endl;
    int result1=secsmallest(arr,n);
    cout<<" second smallest element in the array is "<<result1<<endl;
    
    return 0;
}

/*
        TC=O(n);better case
*/