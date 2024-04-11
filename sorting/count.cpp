#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v{9,7,5,3,1};
	map<int,int>mp;
	vector<int>Ans;
	for(auto i:v){
		mp[i]++;
	}
	for(auto i:mp){
		int num=i.first;
		int freq=i.second;
		while(freq--){
			Ans.push_back(num);
		}
	}
	for(auto i :Ans){
		cout<<i<<" ";
	}
	return 0;
}