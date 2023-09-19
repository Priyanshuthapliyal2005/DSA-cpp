#include<iostream>
using namespace std;
void explainpairs(){
    pair<int,long>p;
    p=make_pair(2,6);
    cout<<p.first<<" "<<p.second<<endl;

    //declare pair of array 
    pair<int,int>arr[2];
    for(int i=0;i<2;i++){
    cin>>arr[i].first;
    cin>>arr[i].second;}
    for(int i=0;i<2;i++){

    cout<<arr[i].first<<" "<<arr[i].second<<endl;}
}
int main(){
    explainpairs();
    return 0;
}