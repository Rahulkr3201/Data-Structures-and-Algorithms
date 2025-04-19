int printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // Base case
    if (ind == n)
    {
        // Condition satisfied
        if (s == sum)
            return 1;
        // Condition not satisfied
        else
            return 0;
    }

    // Pick the element
    ds.push_back(arr[ind]);
    s += arr[ind];
    int l = printS(ind + 1, ds, s, sum, arr, n);

    // Backtrack
    s -= arr[ind];
    ds.pop_back();

    // Not pick the element
    int r = printS(ind + 1, ds, s, sum, arr, n);

    return l + r;
}
// we know to print all subsequence with sum;
// we know to print any one using the bool function in recursion
//  this is code for print total no of sequence with sum==k;