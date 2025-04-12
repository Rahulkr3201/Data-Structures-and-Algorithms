class Solution
{
public:
    int countCollisions(string directions)
    {
        stack<char> s;
        int count = 0;
        for (auto it : directions)
        {
            if (it == 'R')
            {
                s.push(it);
            }
            else if (it == 'L')
            {
                if (!s.empty() && s.top() == 'R')
                {

                    while (!s.empty() && s.top() == 'R')
                    {
                        s.pop();
                        count++;
                    }
                    count++;
                    s.push('S');
                }
                else if (!s.empty() && s.top() == 'S')
                {
                    count++;
                }
            }
            else if (it == 'S')
            {
                while (!s.empty() && s.top() == 'R')
                {
                    s.pop();
                    count++;
                }
                s.push('S');
            }
        }
        return count;
    }
};
