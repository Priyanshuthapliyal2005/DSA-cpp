#include<bits/stdc++.h>

using namespace std;


// int linearSearch(vector<int>&v,int k)
// {
//     for(int i=0;i<v.size();i++){
//         if(v[i]==k)return i;
//     }
//     return INT_MAX;
// }

int linearSearch(vector<int>& v, int i, int k) {
    if (i == v.size()) // Base case: If i reaches the end of the array, element not found
        return INT_MAX;
    if (v[i] == k) // If current element matches the target value
        return i;
    else
        return linearSearch(v, i + 1, k); // Recursive call with next index
}


int main()
{
    vector<int>v{1,2,1,2,1,2,4,5,12};
    cout<<"Origional array:";
    for(auto i:v){
        cout<<i<<" ";
    }
    int k = 0;
    cout << "\nEnter the element you want to find in array: ";
    cin >> k;
    int i=linearSearch(v,0,k);
    if (i != INT_MAX)
        cout << "Element found at index is" << i;
    else
        cout << "Element not found";

    return 0;
}