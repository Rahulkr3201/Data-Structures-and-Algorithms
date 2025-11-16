#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    // Outer loop → goes through every position in the array
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // assume current index has the smallest element

        // Inner loop → find actual minimum element in the remaining unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // update index of minimum element
            }
        }

        // Swap the found minimum element with element at i
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    cout << "Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------------
🧠 CONCEPT:
Selection Sort picks the smallest element from
the unsorted part and places it at the beginning.

- Outer loop: selects the position to fill
- Inner loop: finds the minimum element
- Swap: place that element at correct position

⏱️ Time Complexity:
Best: O(n²)
Worst: O(n²)
Space: O(1)
Stable: ❌ (not stable)
-----------------------------------------------
*/
