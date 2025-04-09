class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        for (auto it : asteroids)
        {
            bool destroyed = false;
            while (!s.empty() && it < 0 && s.top() > 0)
            {
                if (it * -1 < s.top())
                {
                    destroyed = true;
                    break;
                }
                else if (it * -1 > s.top())
                {
                    s.pop();
                }
                else
                {
                    s.pop();
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed)
            {
                s.push(it);
            }
        }
        vector<int> ans(s.size());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};