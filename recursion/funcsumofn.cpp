#include<iostream>
using namespace std;

void sumN(int i, int sum) {
    if (i == 0) {
        cout << "Sum of first " << i << " numbers: " << sum;
        return;
    }
    sumN(i - 1, sum + i);
}

int main() {
    int n;
    cout << "Enter first N numbers:";
    cin >> n;
    sumN(n, 0);
    return 0;
}
