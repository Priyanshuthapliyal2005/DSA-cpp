#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> &v,int low,int high){
    srand(time(NULL));
    int RandomIndex=low + rand() % (high - low + 1);
    swap(v[low],v[RandomIndex]);
    int pivot=v[low];
    int i=low;
    int j=high;

    while(i<j){
        while(v[i]<=pivot && i<=high)i++;
        while(v[j]>pivot && j>=low)j--;
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}

void quickSort(vector<int> &v,int low,int high){
    if(low<high){
        int pI=partition(v,low,high);
        quickSort(v,low,pI-1);
        quickSort(v,pI+1,high);
    }
}


void randomisedSort(vector<int> &v,int low,int high){
    
}

int main(){
    // vector<int>v{6,5,4,3};
    // vector<int>v{1,3,2,5,4};
    vector<int>v{9,7,5,3,1};


    cout << "Original array: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl; // Print newline after original array

    quickSort(v, 0, v.size() - 1);

    cout << "Quick sort sorted array: ";
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}