class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                if (piles[i] % mid == 0)
                {
                    hours = (hours + piles[i] / mid);
                }
                else
                    hours = hours + (piles[i] / mid) + 1;
            }

            if (hours <= h)
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};
