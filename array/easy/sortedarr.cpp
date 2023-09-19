#include<iostream>
#include<vector>
using namespace std;
int issorted(vector<int>&arr,int n){
     for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    vector<int>arr={1,1,2,2,3};
    int n=arr.size();
    bool result=issorted(arr,n);
    if(result==false){
        cout<<" array is not sorted "<<endl;
    }
    else
        cout<<" array is sorted "<<endl;
    
    return 0;
}