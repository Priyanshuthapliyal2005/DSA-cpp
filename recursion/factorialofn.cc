#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0)return 1;
    return n*factorial(n-1);
}
int main()
{
    int n;
    cout<<"enter the number for its factorial:";
    cin>>n;
    cout<<"factorial of "<< n <<" is ";
    int n1=factorial(n);
    cout<<n1;
    return 0;
}