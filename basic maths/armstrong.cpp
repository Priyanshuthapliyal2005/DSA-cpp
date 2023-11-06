#include<iostream>
#include<cmath>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int arm(int n) {
    int sum = 0;
    int power = countDigits(n);
    int temp = n;

    while (temp > 0) {
        int ld = temp % 10;
        sum = sum + pow(ld, power);
        temp = temp / 10;
    }
    return sum;
}

int main() {
    int n;
    cout << "enter the number: ";
    cin >> n;
    int n1 = arm(n);
    if (n1 == n) {
        cout << n << " is an Armstrong number";
    }
    else {
        cout << n << " is not an Armstrong number";
    }
    return 0;
}
