class Solution
{
public:
    int count = 0;

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] > arr[right])
            {
                temp.push_back(arr[right]);
                if (arr[left] > 2 * arrr[right])
                    count = count + (mid - left) + 1;

                right++;
            }
            else
            {
                temp.push_back(arr[left]);
                left++;
            }
        }
        while (left <= mid)
            temp.push_back(arr[left++]);
        while (right <= high)
            temp.push_back(arr[right++]);

        for (int k = low; k <= high; k++)
        {
            arr[k] = temp[k - low];
        }
    }
    void mergesort(vector<int> &arr, int low, int high)
    {

        if (low >= high)
            return;
        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    int inversionCount(vector<int> &arr)
    {

        mergesort(arr, 0, arr.size() - 1);
        return count;
        // Code Here
    }
};