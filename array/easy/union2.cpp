#include<iostream>
#include<vector>
using namespace std;
vector<int>sortedarr(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();
    int i=0,j=0;
    vector<int>uni;
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){
            if(uni.size()==0||uni.back()!=a[i]){
                uni.push_back(a[i]);
            }
            i++;
        }
        else{
            if(uni.size()==0||uni.back()!=b[j]){
                uni.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(uni.size()==0||uni.back()!=b[j]){
                uni.push_back(b[j]);
            }
            j++;
    }
    while(i<n1){
        if(uni.size()==0||uni.back()!=a[i]){
                uni.push_back(a[i]);
            }
            i++;
    }
    return uni;
}
int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 3, 4, 6};

    vector<int> result = sortedarr(a, b);

    cout << "Sorted Union: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}