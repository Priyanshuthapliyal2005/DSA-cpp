#include<iostream>
#include<vector>
using namespace std;
vector<int>inter(vector<int>a,vector<int>b,int n,int m){
    int i=0,j=0;
    vector<int>ans;
    while (i<n&&j<m)
    {
        if(a[i]<b[j])i++;
        else if(a[i]>b[j])j++;
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    } 
    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {3, 4, 5, 6, 7};
    int n = a.size();
    int m = b.size();

    vector<int> result = inter(a, b, n, m);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}