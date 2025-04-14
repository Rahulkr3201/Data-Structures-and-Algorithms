#include <bits/stdc++.h>
using namespace std;

void sequence(int index, vector<int> &ar, vector<int> &temp)
{
    int n = ar.size();
    if (index >= n)
    {
        for (auto it : temp)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // time complexity is near about 2^n + n for the printing

    temp.push_back(ar[index]);
    sequence(index + 1, ar, temp);
    temp.pop_back();
    sequence(index + 1, ar, temp);
}
int main()
{
    vector<int> ar = {3, 1, 2};

    vector<int> temp;
    sequence(0, ar, temp);
}