class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        set<string> mySet;
        for (auto it : wordList)
        {
            mySet.insert(it);
        }
        mySet.erase(beginWord);
        q.push({beginWord, 1});
        while (!q.empty())
        {
            string word = q.front().first;
            string temp = word;
            int level = q.front().second;
            q.pop();
            int length = word.length();
            for (int i = 0; i < length; i++)
            {
                word = temp;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (mySet.find(word) != mySet.end())
                    {
                        if (word == endWord)
                            return level + 1;
                        q.push({word, level + 1});
                        mySet.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};