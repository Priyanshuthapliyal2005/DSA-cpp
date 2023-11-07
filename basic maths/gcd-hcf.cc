#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main() {
    int n, m;
    
    cout << "Enter the first number: ";
    cin >> n;
    
    cout << "Enter the second number: ";
    cin >> m;
    
    int n1 = gcd(n, m);
    
    cout << "GCD of " << n << " and " << m << " is: " << n1 << endl;
    
    return 0;
}
