#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        unordered_set<int> present(a.begin(), a.end());
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++)
        {
            visited[a[i]] = false;
        }

        vector<int> B;

        for (int i = 0; i < n; i++)
        {
            int x = a[i];

            if (visited[x])
                continue;

            bool possible = true;

            // Check ALL multiples of x up to k
            for (long long m = x; m <= k; m += x)
            {
                if (!present.count(m))
                {
                    possible = false;
                    break;
                }
            }

            if (possible)
            {
                B.push_back(x);

                for (long long m = x; m <= k; m += x)
                {
                    if (visited.count(m))
                        visited[m] = true;
                }
            }
        }

        bool ok = true;
        for (int x : a)
        {
            if (!visited[x])
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << B.size() << "\n";
            for (int x : B)
                cout << x << " ";
            cout << "\n";
        }
    }
}
