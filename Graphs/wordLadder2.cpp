#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    void dfs(string word, set<string> &s, string endWord, vector<vector<string>> &ans, vector<string> v)
    {
        int length = word.length();
        string temp = word;
        for (int i = 0; i < length; i++)
        {
            word = temp;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    v.push_back(word);
                    if (word == endWord)
                    {
                        ans.push_back(v);
                        return;
                    }
                    dfs(word, s, endWord, ans, v);
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        set<string> s;
        vector<string> v;
        v.push_back(beginWord);
        for (auto it : wordList)
        {
            s.insert(it);
        }
        s.erase(beginWord);
        dfs(beginWord, s, endWord, ans, v);
        return ans;
    }
};

int main()
{
    Solution solution;

    // Hardcoded input for beginWord, endWord and wordList
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Calling the findLadders function
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);

    // Printing the result
    cout << "All transformation sequences: " << endl;
    for (auto sequence : result)
    {
        for (auto w : sequence)
        {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
