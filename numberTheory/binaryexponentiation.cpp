// why do we sue this , we use this because it will take very high velue if you do a power b a^b. which will not be able to get stored in the data typr
//  also we have to run for o(n )times the loop
// this tc is o(log2N);
#include <bits/stdc++.h>
using namespace std;

int binaryexpo(int a, int b)
{

    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int ans;

    if (b % 2 == 1)
    {
        int x = binaryexpo(a, b / 2); // 3^2 will be computed from here
        ans = (x * x * a);            // 3^5=3^2*3^2*3;
    }
    else
    {
        int y = binaryexpo(a, b / 2);
        ans = (y * y);
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << "previous value" << pow(a, b) << endl;
    cout << "after value" << binaryexpo(a, b) << endl;
}