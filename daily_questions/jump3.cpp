class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        stack<int> s;
        int n = arr.size();
        vector<bool> visited(n + 1, false);
        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            int forward = top + arr[top];
            if (forward < n && arr[forward] == 0)
                return true;
            else
            {
                if (forward < n && !visited[forward])
                {
                    s.push(forward);
                    visited[forward] = true;
                }
            }
            int backward = top - arr[top];
            if (backward >= 0 && arr[backward] == 0)
                return true;
            else
            {
                if (backward >= 0 && !visited[backward])
                {
                    s.push(backward);
                    visited[backward] = true;
                };
            }
        }
        return false;
    }
};