#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int odd = 0;
        int maxindex = max_element(a.begin(), a.end()) - a.begin();
        a[maxindex]--;
        if (*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) > k)
        {
            cout << "Jerry" << endl;
        }

        else
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j] % 2 != 0)
                    odd++;
            }
            if (odd % 2 == 0)
            {
                cout << "Tom" << endl;
            }
            else
            {
                cout << "Jerry" << endl;
            }
        }
    }
    return 0;
}