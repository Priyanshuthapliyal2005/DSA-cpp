#include<bits/stdc++.h>
using namespace std;

// void bubbleSort(vector<int> &v){
//     for(int i=0;i<v.size();i++){
//         for(int j=i+1;j<v.size();j++){
//             if(v[i]>v[j])
//                 swap(v[i],v[j]);
//         }
//     }
// }

void bubbleSort (vector<int>&v){
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main()
{
    vector<int> v={1,5,2,4,3,2,1 };

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