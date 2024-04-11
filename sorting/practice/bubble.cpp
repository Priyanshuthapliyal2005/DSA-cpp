#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j])
                swap(v[i],v[j]);
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
    bubbleSort(v);
    cout<<"Bubble sort sorted array: ";
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}