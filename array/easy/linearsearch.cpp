#include<iostream>
#include<vector>
using namespace std;
int linearsearch(vector<int>& arr,int num){
    int i;
    for(i=0;i<arr.size();i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int>arr={1,2,5,4,2,1};
    int num;
    cin>>num;
    int result=linearsearch(arr,num);
    if(result!=-1){
        cout<<"first occurence of number found at place: "<<result+1<<endl;
        
    }
    else{
        cout<<"number not found "<<endl;
    }
    return 0;
}