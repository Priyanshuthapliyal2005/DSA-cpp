#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int XOR1 = 0;
    int XOR2 = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        XOR2 = XOR2 ^ nums[i];
        XOR1 = XOR1 ^ (i + 1);
    }
    
    return XOR1 ^ XOR2;
}

int main() {
    vector<int> nums = {0, 1, 3, 4, 5};
    int result = missingNumber(nums);
    cout << result << endl;
    return 0;
}
