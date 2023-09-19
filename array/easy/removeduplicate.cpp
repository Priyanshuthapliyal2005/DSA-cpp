#include<iostream>
#include<vector>
using namespace std;
int remduplicate(vector<int>&arr,int n){
     if (n == 0 || n == 1) {
        return n;
    }

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[j] != arr[i]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
int main(){
    vector<int>arr={1,1,2,2,3};
    int n=arr.size();
    int result=remduplicate(arr,n);
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}