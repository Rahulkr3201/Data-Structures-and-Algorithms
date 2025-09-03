class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int ops = 0;

        while (target > startValue)
        {
            if (target % 2 == 0)
            {
                target /= 2; // reverse of multiply
            }
            else
            {
                target += 1; // reverse of subtract
            }
            ops++;
        }

        // if startValue is bigger, only way is subtracting
        return ops + (startValue - target);
    }
};
