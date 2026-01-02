#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a = 48, b = 18;

    cout << gcd(a, b) << endl; // Output: 6
    // we can also use inbuilt fn gcd(a,b)in c++17
    return 0;
}
