class Solution
{
public:
    int recursion(int index, vector<vector<int>> &jobs, vector<int> &startTime, vector<int> &dp)
    {
        int n = jobs.size();
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // find next job index whose start >= current job's end
        int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[index][1]) - startTime.begin();

        int take = jobs[index][2] + recursion(nextIndex, jobs, startTime, dp);
        int notTake = recursion(index + 1, jobs, startTime, dp);

        return dp[index] = max(take, notTake);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();

        // Step 1: store all jobs in vector<vector<int>>
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Step 2: sort jobs by start time
        sort(jobs.begin(), jobs.end());

        // Step 3: extract sorted startTime (for lower_bound)
        for (int i = 0; i < n; i++)
        {
            startTime[i] = jobs[i][0];
        }

        // Step 4: create dp
        vector<int> dp(n, -1);

        // Step 5: call recursion with dp
        return recursion(0, jobs, startTime, dp);
    }
};
//
recursion(0) |
    | --take job 0(profit 50) | |
    | | --recursion(2) | |
    | | --take job 2(profit 40) | | | --recursion(4) : 0 | |
    | | --not take job 2 | | --recursion(3) | | --take job 3(profit 70) | | | --recursion(4) : 0 | |
    | | --not take job 3 | | --recursion(4) : 0 |
    | --not take job 0 |
    | --recursion(1) |
    | --take job 1(profit 10) | | --recursion(2)(same as above) |
    | --not take job 1 | --recursion(2)(same as above)
