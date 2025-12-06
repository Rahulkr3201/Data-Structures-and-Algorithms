#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (auto &x : a)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        long long mini = 0, maxi = 0; // initial score range = [0,0]

        for (int i = 0; i < n; i++)
        {

            // 4 possible transitions
            long long t1 = mini - a[i]; // from mini using red
            long long t2 = maxi - a[i]; // from maxi using red
            long long t3 = b[i] - mini; // from mini using blue
            long long t4 = b[i] - maxi; // from maxi using blue

            // new interval from min/max of these 4
            long long new_mini = min({t1, t2, t3, t4});
            long long new_maxi = max({t1, t2, t3, t4});

            mini = new_mini;
            maxi = new_maxi;
        }

        cout << maxi << "\n"; // answer = maximum reachable score
    }

    return 0;
}
