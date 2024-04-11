// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// void merge(vector<int> &v, int low, int mid, int high) {
//     int n1 = mid - low + 1;
//     int n2 = high - mid;
//     vector<int> Left(n1);
//     vector<int> Right(n2);

//     for (int i = 0; i < n1; i++) {
//         Left[i] = v[i + low];
//     }
//     for (int j = 0; j < n2; j++) {
//         Right[j] = v[mid + j + 1];
//     }

//     int i = 0, j = 0, k = low;

//     while (i < n1 && j < n2) {
//         if (Left[i] <= Right[j]) {
//             v[k++] = Left[i++];
//         } else {
//             v[k++] = Right[j++];
//         }
//     }

//     while (i < n1) {
//         v[k++] = Left[i++];
//     }
//     while (j < n2) {
//         v[k++] = Right[j++];
//     }
// }



// void mergeSort(vector<int> &v,int low,int high){
//     if(low<high){
//         int mid=low+(high-low)/2;
//         mergeSort(v,low,mid);
//         mergeSort(v,mid+1,high);
//         merge(v,low,mid,high);
//     }
// }

// int main()
// {
//     vector<int>v{1,2,3,3,2,1,90,98,67,1,2,3,3,21,1};

//     cout << "Original array: ";
//     for (auto i : v) {
//         cout << i << " ";
//     }
//     cout << endl; // Print newline after original array

//     mergeSort(v, 0, v.size() - 1);

//     cout << "Merge sort sorted array: ";
//     for (auto i : v) {
//         cout << i << " ";
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// void merge_Sort(vector<int>&v,int low,int mid,int high){
//     int n1=mid-low+1;
//     int n2=high-mid;
//     vector<int>Left(n1),Right(n2);

//     for(int i=0;i<n1;i++) Left[i]=v[i+low];
//     for(int i=0;i<n2;i++) Right[i]=v[mid+i+1];

//     int i=0,j=0,k=low;
//     while(i<n1 && j<n2){
//         if(Left[i]<=Right[j]){
//             v[k++]=Left[i++];
//         }else{
//             v[k++]=Right[j++];
//         }
//     }
//     while(i<n1)
//         v[k++]=Left[i++];
//     while(j<n2)
//         v[k++]=Right[j++];
        

// }

// void merge(vector<int> &v,int low,int high){
//     if(low<high){
//         int mid=low+(high-low)/2;
//         merge(v,low,mid);
//         merge(v,mid+1,high);
//         merge_Sort(v,low,mid,high);
//     }
// }

// int main(){
//     vector<int>v{1,2,3,3,2,1,90,98,67,1,2,3,3,21,1};

//     cout<<"Original array:";
//     for(auto i :v)cout<<i<<" ";

//     cout<<endl;
//     merge(v,0,v.size()-1);

//     cout<<"Merge Siort sorted array:";
//     for(auto i:v)cout<<i<<" ";
// }