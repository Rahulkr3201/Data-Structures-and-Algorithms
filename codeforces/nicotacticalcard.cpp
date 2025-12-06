#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        long long k = 0;
        long long maxi = max(k - a[0], b[0] - k);
        long long mini = min(k - a[0], b[0] - k);

        for (int i = 1; i < n; i++)
        {

            long long new_maxi = max(b[i] - mini, maxi - a[i]);
            long long new_mini = min(mini - a[i], b[i] - maxi);

            maxi = new_maxi;
            mini = new_mini;
        }
        cout << maxi << endl;
    }
}