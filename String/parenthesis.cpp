#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void sequence(vector<string> &ans, string temp, int n, int open, int close)
    {
        if (open == n && close == n)
        {
            ans.push_back(temp);

            return;
        }

        if (open < n)
        {
            // temp.push_back('(');
            // open++;
            sequence(ans, temp + '(', n, open + 1, close);
        }

        if (close < open)
        {
            // temp.push_back(')');//this is not a good method thiis is changig the mainn open and close value of the first function call
            // close++;
            sequence(ans, temp + ')', n, open, close + 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        vector<string> ans;
        string temp = "("; // Correct initialization
        int open = 0;
        int close = 0;
        sequence(ans, temp, n, open, close);
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 2; // Test case for n = 2
    vector<string> result = sol.generateParenthesis(n);

    cout << "Generated Parentheses for n = " << n << ": \n";
    for (auto it : result)
    {
        cout << it << endl;
    }

    return 0;
}
