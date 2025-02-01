#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    int n;
    n = 5;
    int ans = 0;
    ans = fact(n);
    cout << ans << endl;
}