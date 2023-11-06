#include <iostream>
#include <cmath>
using namespace std;

int prime(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            count++;
            if ((n / i) != i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int n1 = prime(n);
    if (n1 == 2) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    return 0;
}
