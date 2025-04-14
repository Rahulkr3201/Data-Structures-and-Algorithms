#include <bits/stdc++.h>
using namespace std;

void recursive(int index, vector<int> &nums, int sum, int k, int &count, vector<int> &temp)
{
    int n = nums.size();
    if (index == n)
    {
        if (sum == k)
        {
            count++;
        }
        return;
    }

    temp.push_back(nums[index]);
    // sum = sum + nums[index]; this is error because for not taking 1 our sum will be 1 only that should be zero;
    recursive(index + 1, nums, sum + nums[index], k, count, temp);
    temp.pop_back();
    recursive(index + 1, nums, sum, k, count, temp);
}
int countSubsequenceWithTargetSum(vector<int> &nums, int k)
{
    // your code goes here
    vector<int> temp;
    int count = 0;
    recursive(0, nums, 0, k, count, temp);
    for (auto it : temp)
    {
        cout << it << " ";
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 1};
    int k = 2;
    int ans = countSubsequenceWithTargetSum(arr, k);
    cout << ans << endl;
    return 0;
}
