#include<iostream>
#include<vector>
using namespace std;
void explainvectors(){
    int n;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<v[0]<<" ";
    }
int main(){
    explainvectors();
    return 0;
}