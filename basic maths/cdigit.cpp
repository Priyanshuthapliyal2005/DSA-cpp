#include<iostream>
using namespace std;
void count(int n){
    int count=0;
    if(n>=0){
        while(n>0){
        int lastd=n%10;
        count+=1;
        n=n/10;
        }
    }
    else{
        n=n/-1;
        while(n>0){
        int lastd=n%10;
        count+=1;
        n=n/10;
    }
    }
    
    cout<<"Number of digits are:"<<count;
}
int main()
{
    int n;
    cout<<"enter the number: ";
    cin>>n;
    count(n);
    return 0;
}