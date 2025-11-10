class Solution
{
public:
    int count = 0;

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;

        // Step 1: Count reverse pairs before merging
        for (int left = low; left <= mid; left++)
        {
            while (right <= high && (long long)arr[left] > 2LL * arr[right])
                right++;
            count += (right - (mid + 1));
        }

        // Step 2: Normal merge logic (your same code)
        vector<int> temp;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= high)
            temp.push_back(arr[j++]);

        for (int k = low; k <= high; k++)
            arr[k] = temp[k - low];
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

    int reversePairs(vector<int> &nums)
    {
        count = 0;
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
};
