class Solution
{
public:
    string minWindow(string s, string t)
    {
        int need[128] = {0};    // Required counts for each char
        int current[128] = {0}; // Counts in current window
        int required = 0;       // Number of unique chars to satisfy

        // Fill need array and count unique required characters
        for (char c : t)
        {
            if (need[c] == 0)
                required++;
            need[c]++;
        }

        int have = 0; // Number of chars fully satisfied in window
        int i = 0, ansStart = 0, ansLen = INT_MAX;

        // Sliding window
        for (int j = 0; j < s.size(); j++)
        {
            char c = s[j];

            // Expand window
            if (need[c] > 0)
            {
                current[c]++;
                if (current[c] == need[c])
                    have++; // char fully satisfied
            }

            // Shrink window from left while all required chars are satisfied
            while (have == required)
            {
                if (j - i + 1 < ansLen)
                {
                    ansLen = j - i + 1;
                    ansStart = i;
                }

                char leftChar = s[i++];
                if (need[leftChar] > 0)
                {
                    current[leftChar]--;
                    if (current[leftChar] < need[leftChar])
                        have--; // no longer satisfied
                }
            }
        }

        return ansLen == INT_MAX ? "" : s.substr(ansStart, ansLen);
    }
};
