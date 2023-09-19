#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> longestsubarray(vector<int> a, long long k) {
    int left = 0, right = 0;
    long long sum = a[0];
    int maxlen = 0;
    pair<int, vector<int>> result; // Pair to store length and elements of the longest subarray
    int n = a.size();
    
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if (sum == k && (right - left + 1) > maxlen) {
            maxlen = right - left + 1;
            result = make_pair(maxlen, vector<int>(a.begin() + left, a.begin() + right + 1));
        }
        right++;
        if (right < n) sum += a[right];
    }
    
    return result;
}

int main() {
    long long k;
    pair<int, vector<int>> result;
    vector<int> a = {1, 2, 4, 1, 6, 2, 2, 8, 3, 9};
    
    cout << "Enter the sum which you want: ";
    cin >> k;
    
    result = longestsubarray(a, k);
    
    if (result.first == 0) {
        cout << "No subarray found with the given sum constraint." << endl;
    } else {
        cout << "Length of the longest subarray: " << result.first << endl;
        cout << "Elements of the longest subarray: ";
        for (int num : result.second) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
