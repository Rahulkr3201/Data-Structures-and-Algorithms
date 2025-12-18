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
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        vector<bool> deleted(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (deleted[i])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (num[i] > num[j] && !deleted[j])
                {
                    ans++;
                    deleted[j] = true;
                }
            }
        }
        cout << ans << endl;
    }
}