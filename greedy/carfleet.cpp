class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        // Pair up position and speed
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position (ascending)
        sort(cars.begin(), cars.end());

        // Compute time to reach target
        vector<float> time(n);
        for (int i = 0; i < n; i++)
        {
            int pos = cars[i].first;
            int spd = cars[i].second;
            time[i] = (float)(target - pos) / spd;
        }

        int fleet = 0;
        float curMax = 0.0;

        // Traverse from rightmost car backwards
        for (int i = n - 1; i >= 0; i--)
        {
            if (time[i] > curMax)
            {
                fleet++;          // forms a new fleet
                curMax = time[i]; // update fleet time
            }
            // else merges into current fleet (do nothing)
        }

        return fleet;
    }
};
