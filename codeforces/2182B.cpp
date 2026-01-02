#include <bits/stdc++.h>
using namespace std;

int play(int a, int b, bool whiteStarts)
{
    int platesize = 1;
    int level = 0;
    bool Turn = whiteStarts;

    while (true)
    {
        if (Turn)
        {
            if (a < platesize)
                break;
            a -= platesize;
        }
        else
        {
            if (b < platesize)
                break;
            b -= platesize;
        }

        level++;
        platesize = 2 * platesize;
        Turn = !Turn;
    }

    return level;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int whiteFirst = play(a, b, true); // explore white start
        int darkFirst = play(a, b, false); // explore dark start

        cout << max(whiteFirst, darkFirst) << '\n';
    }
}
