#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin>>num;

    vector<int>nums;
    for(int i=0;i<num;i++){
        int k;
        cin>>k;
        nums.push_back(k);
    }

    int k;
    cin>>k;

    unordered_map<int,int>u;

    for(auto i : nums)u[i]++;

    priority_queue<pair<int,int>>pq;

    for (auto it : u) pq.push({it.second, it.first});

    while(k--){
        int top=pq.top().second;
        pq.pop();
        cout<<top<<" ";
    }

    return 0;
}