/* 
bubble sort

t.c={
    o(n*n);worst case
    o(n);best case
}

*/
#include<bits/stdc++.h>
using namespace std;
void b_s(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        int didswap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                didswap=1;
            }
        }
        if(didswap==0){
            break;
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
    b_s(arr,n);
    cout<<"sorted array:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}