class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long n = bloomDay.size();
        if (n < (long long)m * k)
            return -1;

        long long smallest = INT_MAX;
        long long largest = INT_MIN;

        for (auto day : bloomDay)
        {
            smallest = min(smallest, (long long)day);
            largest = max(largest, (long long)day);
        }

        while (smallest <= largest)
        {
            long long mid = (smallest + largest) / 2;

            long long flower = 0;
            long long count = 0;

            for (auto day : bloomDay)
            {
                if (day <= mid)
                {
                    flower++;
                    if (flower == k)
                    {
                        count++;
                        flower = 0;
                    }
                }
                else
                {
                    flower = 0;
                }
            }

            if (count >= m)
            {
                largest = mid - 1;
            }
            else
            {
                smallest = mid + 1;
            }
        }

        return (int)smallest;
    }
};
