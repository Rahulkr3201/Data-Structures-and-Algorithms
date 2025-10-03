class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        int n = words.size();

        // Step 1: Build graph edges from adjacent words
        for (int i = 0; i < n - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());

            // ✅ Fix 1: handle invalid prefix case
            if (word1.size() > word2.size() && word1.substr(0, len) == word2.substr(0, len))
            {
                return "";
            }

            for (int j = 0; j < len; j++)
            {
                if (word1[j] != word2[j])
                {
                    graph[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    break; // only first differing character matters
                }
            }
        }

        // Step 2: Collect all unique characters
        unordered_set<char> st;
        for (auto &word : words)
        {
            for (auto c : word)
            {
                st.insert(c);
                if (indegree.find(c) == indegree.end())
                    indegree[c] = 0;
            }
        }

        // Step 3: Topological sort using Kahn's Algorithm
        queue<char> q;
        for (auto ch : st)
        {
            if (indegree[ch] == 0)
            {
                q.push(ch);
            }
        }

        string result;
        while (!q.empty())
        {
            char top = q.front();
            result += top;
            q.pop();

            for (auto neigh : graph[top])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Step 4: If cycle exists → invalid
        if (result.size() != st.size())
        {
            return "";
        }

        // ✅ Fix 2: return result instead of true
        return result;
    }
};
