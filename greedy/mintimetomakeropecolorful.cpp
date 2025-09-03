class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int totaltime = 0;
        int sum = neededTime[0];
        int maxtime = neededTime[0];

        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] == colors[i - 1])
            {
                maxtime = max(maxtime, neededTime[i]);
                sum = sum + neededTime[i];
            }
            else
            {
                totaltime += sum - maxtime;
                maxtime = neededTime[i];
                sum = neededTime[i];
            }
        }
        totaltime += sum - maxtime;
        return totaltime;
    }
};