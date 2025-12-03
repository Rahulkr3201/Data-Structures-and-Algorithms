#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, j, k;
        cin >> n;
        cin >> j;
        cin >> k;

        string n1 = to_string(n);

        vector<string> per;
        per.push_back(n1);

        while (next_permutation(n1.begin(), n1.end()))
        {
            per.push_back(n1);
        }

        string temp1 = per[j - 1];
        string temp2 = per[k - 1];

        int A = 0;
        for (int i = 0; i < temp1.length(); i++)
        {
            if (temp1[i] == temp2[i])
                A++;
        }
        int B = temp1.length() - A;

        cout << A << "A" << B << "B" << endl;
    }
}
