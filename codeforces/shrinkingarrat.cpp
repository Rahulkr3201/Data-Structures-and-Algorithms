#include <bits/stdc++.h>
using namespace std;
int calc(int a[], int n)
{
    for (int i = 2; i <= n; i++)
        if (abs(a[i] - a[i - 1]) <= 1)
            return 0;
    for (int i = 2; i < n; i++)
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
            return 1;
    return -1;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << calc(a, n) << '\n';
    }
    return 0;
}