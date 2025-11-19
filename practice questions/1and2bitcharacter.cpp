class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int index = -1;
        int n = bits.size();

        int i = 0;
        while (i < n - 1)
        {
            if (bits[i] == 1)
            {
                // 2-bit character
                i += 2;
                index = i;
            }
            else
            {
                // 1-bit character
                i += 1;
            }
        }

        return index < n;
    }
};
