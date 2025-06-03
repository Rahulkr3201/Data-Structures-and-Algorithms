class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int maxWeight = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for (auto weight : weights)
        {
            sum += weight;
        }

        int start = maxWeight;
        int end = sum;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int requiredDays = 1;
            int currentLoad = 0;

            for (auto weight : weights)
            {
                if (currentLoad + weight > mid)
                {
                    requiredDays++;
                    currentLoad = 0;
                }
                currentLoad += weight;
            }

            if (requiredDays <= days)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
};
