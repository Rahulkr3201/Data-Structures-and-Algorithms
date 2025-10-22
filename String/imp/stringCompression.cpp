class Solution
{
public:
    int compress(vector<char> &chars)
    {
        string result = "";
        int n = chars.size();
        int i = 0;

        while (i < n)
        {
            char current = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while (i < n && chars[i] == current)
            {
                i++;
                count++;
            }

            // Append the character
            result += current;

            // Append count as separate chars if > 1
            if (count > 1)
            {
                string countStr = to_string(count);
                result += countStr; // automatically adds each digit
            }
        }

        // Clear original chars and push new compressed string
        chars.clear();
        for (char c : result)
        {
            chars.push_back(c);
        }

        return chars.size(); // return new length
    }
};
