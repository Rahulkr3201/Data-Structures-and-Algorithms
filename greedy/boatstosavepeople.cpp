class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end()); // Sort people by weight
        int n = people.size();
        int boats = 0;
        int i = 0, j = n - 1;

        while (i <= j)
        {
            // Always try to put the heaviest person with the lightest
            if (people[i] + people[j] <= limit)
            {
                i++;
                // Lightest person gets on board
            }
            j--; // Heaviest person gets on board
            // One boat used
            boats++;
        }

        return boats;
    }
};
