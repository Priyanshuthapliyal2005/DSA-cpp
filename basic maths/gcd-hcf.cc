#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;
    return a;
}

int main()
{
    int n, m;
    cout << "enter a number";
    cin >> n;
    cout << "enter a number";
    cin >> m;
    int n1 = gcd(n, m);
    cout << "Hcf of " << n << " & "
         << m<< " is :" << n1;
    return 0;
}