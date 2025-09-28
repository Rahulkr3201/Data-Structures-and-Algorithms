class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string temp = s;
        int n = part.size();

        while (temp.find(part) != string::npos)
        {
            int index = temp.find(part);
            temp = temp.erase(index, n);
        }
        return temp;
    }
};