#include <bits/stdc++.h>

using namespace std;

// int binarySearch(vector<int>& v, int k) {
//     int start = 0;
//     int end = v.size() - 1;
//     while (start <= end) {
//         int mid = start + (end - start) / 2;
//         if (v[mid] == k)
//             return mid;
//         else if (v[mid] < k)
//             start = mid + 1;
//         else
//             end = mid - 1;
//     }
//     return -1;
// }

int binarySearch(vector<int>v,int start,int end,int k){
    if(start<=end){
        int mid=start+(end-start)/2;
        if(v[mid]==k)return mid;
        else if(v[mid]<k)return binarySearch(v,mid+1,end,k);
        else return binarySearch(v,start,mid-1,k);
    }
    return -1;
}


int main() {
    vector<int> v{1, 2, 2, 4, 12, 13}; // Sorted array
    cout << "Array elements:" << endl;
    for (auto i : v) {
        cout << i << " ";
    }
    int k = 0;
    cout << "\nEnter the element you want to find in array: ";
    cin >> k;
    // int ans = binarySearch(v, k);
    int ans=binarySearch(v,0,v.size()-1,k);
    if (ans != -1)
        cout << "Element found at index " << ans;
    else
        cout << "Element not found";
    return 0;
}