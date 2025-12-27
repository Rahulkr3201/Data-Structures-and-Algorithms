#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] = true)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
    // upto this .
    if (prime[n - 2] == true)
    {
        cout << 2 << " " << n - 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}