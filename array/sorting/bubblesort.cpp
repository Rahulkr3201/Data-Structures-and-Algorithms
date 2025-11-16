#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    // Outer loop → runs n-1 times (each pass moves the largest element to the end)
    for (int i = n - 1; i >= 0; i--)
    {

        // Inner loop → compares adjacent elements
        for (int j = 0; j <= i - 1; j++)
        {

            // Swap if elements are in the wrong order
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        // After each pass, the largest element "bubbles up" to its correct position
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    cout << "Bubble Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------------
🧠 CONCEPT:
Bubble Sort compares adjacent elements and swaps
them if they are out of order. After every pass,
the largest element settles at the end.

- Inner loop: performs adjacent swaps
- Outer loop: reduces unsorted range after each pass

⏱️ Time Complexity:
Best: O(n²)
Worst: O(n²)
Space: O(1)
Stable: ✅ (stable sort)
-----------------------------------------------
*/
