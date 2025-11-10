#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    // Merge two sorted halves
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    // Copy remaining elements
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);

    // Copy back into original array
    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort left half
    mergeSort(arr, left, mid);

    // Sort right half
    mergeSort(arr, mid + 1, right);

    // Merge both halves
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {5, 2, 3, 1, 4};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
