// we will use (a*b)%m =(a%m + b%m )%m;
#include <bits/stdc++.h>
using namespace std;

int binaryexpo(int a, int b, int mod)
{

    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    long long ans;
    int x = binaryexpo(a, b / 2, mod);

    if (b % 2 == 1)
    {
        // 3^2 will be computed from here
        long long temp = (1LL * x % mod * x % mod) % mod; // 1LL becse the overflow is very high specially in int *int if they are bigger.
        ans = (int)(1LL * temp % mod * a % mod) % mod;    // 3^5=3^2*3^2*3;
    }
    else
    {

        ans = (1LL * x % mod * x % mod) % mod;
    }
    return (int)ans;
}

int main()
{
    int a, b, mod;
    cin >> a >> b >> mod;

    // cout << "previous value" << pow(a, b, mod) << endl;
    cout << "after value" << binaryexpo(a, b, mod) << endl;
}