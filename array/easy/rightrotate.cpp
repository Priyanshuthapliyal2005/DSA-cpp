#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> rotate(vector<int>& nums, int k) {
     k = k % nums.size();
    vector<int> temp(k);
    
    for (int i = 0; i < k; i++) {
        temp[i] = nums[nums.size() - k + i];
    }
    
    for (int i = nums.size() - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }
    
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
    return nums;
}
int main(){
    vector<int>nums={2,4,9,7,5};
    int k;
    cin>>k;
    int i;
    vector<int> r;
    r=rotate(nums,k);
    for(i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}