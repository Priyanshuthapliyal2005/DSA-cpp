#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int mini=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[mini]){
                mini=j;
            }
            swap(v[mini],v[i]);
        }
    }
}
int main()
{
    vector<int> v={5,4,3,2,1 };
    cout<<"Original array: ";
    for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    selectionSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}