#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    // Start from second element → treat first as sorted
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // element to insert
        int j = i - 1;

        // Shift all elements greater than key one position right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    cout << "Insertion Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
-----------------------------------------------
🧠 CONCEPT:
Insertion Sort builds the sorted array one element
at a time. Each new element is inserted into the
correct position within the already-sorted part.

- Outer loop: picks the element to insert
- Inner loop: shifts larger elements to the right
- Insert: place element in its correct spot

⏱️ Time Complexity:
Best: O(n)
Worst: O(n²)
Space: O(1)
Stable: ✅ (stable sort)
-----------------------------------------------
*/
