//selection sort in array
//T.C=O(n*n)
#include<iostream>
using namespace std;
void s_s(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
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
    s_s(arr,n);
    cout<<"sorted array:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}