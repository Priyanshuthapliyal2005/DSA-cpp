/* 
insertion  sort

t.c={
    o(n*n);worst case
    o(n);best case
}

*/
#include<bits/stdc++.h>
using namespace std;
void i_s(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
}
int main()
{
    int n;
    printf("enter the size  of array:");
    cin>>n;
    int arr[n],i;
    cout<<"enter the elemnts of array:";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    i_s(arr,n);
    cout<<"sorted array:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}