#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> findMaxConsecutive(vector<int>& nums) {
        unordered_map<int, int> consecutiveCounts;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                cnt = 1;
            } else {
                cnt++;
            }

            consecutiveCounts[nums[i]] = max(consecutiveCounts[nums[i]], cnt);
        }

        return consecutiveCounts;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 2, 2, 2, 2, 4, 4, 4};
    unordered_map<int, int> maxConsecutiveCounts = solution.findMaxConsecutive(nums);

    for (const auto& pair : maxConsecutiveCounts) {
        cout << pair.first << " = " << pair.second << " times" << endl;
    }

    return 0;
}
