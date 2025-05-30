class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        int smallest = 1;
        int largest = *max_element(nums.begin(), nums.end());

        int result = -1;
        while (smallest <= largest)
        {
            int mid = (smallest + largest) / 2;

            int hold = 0;
            for (auto it : nums)
            {
                hold = hold + ceil((double)it / mid);
            }
            if (hold <= threshold)
            {
                result = mid;
                largest = mid - 1;
            }
            else
            {
                smallest = mid + 1;
            }
        }
        return result;
    }
};