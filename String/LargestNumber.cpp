class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<int> temp = nums;
        string result = "";

        while (!temp.empty())
        {
            int bestIndex = 0;

            for (int i = 1; i < temp.size(); i++)
            {

                string AB = to_string(temp[i]) + to_string(temp[bestIndex]);
                cout << "AAB" << AB << endl;
                string BA = to_string(temp[bestIndex]) + to_string(temp[i]);
                cout << "BA" << BA << endl;

                if (AB > BA)
                {
                    bestIndex = i;
                }
            }
            result = result + to_string(temp[bestIndex]);
            temp.erase(temp.begin() + bestIndex);
        }
        if (result[0] == '0')
            return "0";
        return result;
    }
};