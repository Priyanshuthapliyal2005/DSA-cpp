#include<iostream>
using namespace std;

int sumN(int i) {
    if (i == 0) {
        return 0;
    }
    return i+sumN(i-1);
}

int main() {
    int n;
    cout << "Enter first N numbers:";
    cin >> n;
    cout<<"sum of first "<<n<<" numbers is:"<<sumN(n);
    return 0;
}
