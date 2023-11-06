#include<iostream>
using namespace std;
int rev(int n){
    int revN;
    while(n>0){
        int ld=n%10;
        n=n/10;
        revN=(revN*10)+ld;
    }
    return revN;
}
int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;
    int n1=rev(n);
    cout<<"reverse number is:"<<n1;
    return 0;
}