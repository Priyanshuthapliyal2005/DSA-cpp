#include<iostream>
using namespace std;

void sumN(int i, int sum) {
    if (i == 0) {
        cout<< sum;
        return;
    }
    sumN(i - 1, sum + i);
}

int main() {
    int n;
    cout << "Enter first N numbers:";
    cin >> n;
    cout << "Sum of first " << n << " numbers: " ;
    sumN(n, 0);
    return 0;
}
