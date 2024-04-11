// #include<bits/stdc++.h>
// using namespace std;


// // int partition(vector<int> &v,int start,int high){
// //     int pivot =v[start];
// //     int low=start+1;
// //     while(low<=high){
// //        while(v[low]<=pivot && low<=high){
// //             cout<<" low "<<v[low]<<" ";
// //            low++;
// //        }
// //        while(v[high]>pivot && high>=low){
// //             cout<<" high "<<v[high]<<" ";
// //            high--;
// //        }
// //         if(low<high){
// //             cout<<"swap"<<endl;
// //             swap(v[low],v[high]);
// //         }
// //     }
// //     cout<<endl<<"high "<<v[high]<<" "<<"start"<<v[start]<<endl;
// //     swap(v[start],v[high]);
// //     cout<<"outer"<<endl;
// //     cout<<"high "<<v[high]<<" "<<"start"<<v[start]<<endl;
// //     cout<<"returned"<<high<<endl;
// //     return high;
// // }
// int partition(vector<int> &v,int start,int high){
//     int pivot =v[start];
//     int low=start+1;
//     while(low<=high){
//        while(v[low]<pivot && low<=high){
//         cout<<"low"<<v[low]<<endl;
//            low++;
//        }
//        while(v[high]>pivot && high>=low){
//         cout<<"high"<<v[high]<<endl;
//            high--;
//        }
//         if(low<=high){
//             cout<<"Inncerswap "<<v[low]<<" "<<v[high]<<endl;
//             swap(v[low],v[high]);
//             low++;high--;
//         }
//     }
//     cout<<"Outerswap "<<v[low]<<" "<<v[start]<<" "<<v[high]<<endl;
//     swap(v[start],v[high]);
//     cout<<"Returned value: "<<high<<endl;
//     return high;
// }

// void quickSort(vector<int> &v,int low,int high){
//     if(low<high){
//         int pIndex=partition(v,low,high);
//         for(auto i:v){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         quickSort(v,low,pIndex-1);
//         for(auto i:v){
//             cout<<"left subtree"<<i<<" ";
//         }
//         cout<<endl;

//         quickSort(v,pIndex+1,high);
//         for(auto i:v){
//             cout<<"right"<<i<<" ";
//         }
//         cout<<endl;

//     }
// }
// int main(){
//     vector<int>v{1,3,2,5,4};

//     cout << "Original array: ";
//     for (auto i : v) {
//         cout << i << " ";
//     }
//     cout << endl; // Print newline after original array

//     quickSort(v, 0, v.size() - 1);

//     cout << "Quick sort sorted array: ";
//     for (auto i : v) {
//         cout << i << " ";
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int low,int high){
    int pivot=v[low];
    int i=low;
    int j=high;
    while(i<j){
        while(v[i]<=pivot &&i<=high)i++;
        while(v[j]>pivot && j>=low)j--;
        if(i<j)swap(v[i],v[j]);
    }
    swap(v[low],v[j]);
    return j;
}

void quickSort(vector<int>&v,int low ,int high){
    if(low<high){
        int pI=partition(v,low,high);
        quickSort(v,low,pI-1);
        quickSort(v,pI+1,high);
    }
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