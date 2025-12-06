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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int sleep = 0;
        int block = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && block < i)
            {
                sleep++;
            }
            else if (s[i] == '1')
            {
                block = i + k;
            }
        }

        cout << sleep << endl;
    }
    return 0;
}