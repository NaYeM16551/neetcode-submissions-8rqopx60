class Solution {
    pair<int,int> getDistinction(const string&word1,const string& word2)
    {
        int i=0;
        for(;i<min(word1.size(),word2.size());++i)
        {
            if(word1[i]!=word2[i])
               return {word1[i]-97,word2[i]-97};
        }
        if(word1.size()==word2.size() or i<word2.size())
          return {word1[word1.size()-1]-97,word2[i]-97};
        else if(word1.size()>word2.size())
         return {-5,-5};  

        return {-1,-1};

    }
public:
    string foreignDictionary(vector<string>& words) {

         unordered_map<char, vector<char>> adj;
    unordered_map<char, int> indegree;

    // 1. Initialize nodes (all chars with indegree 0)
    for (auto &w : words) {
        for (char c : w) {
            if (!indegree.count(c)) {
                indegree[c] = 0;
            }
        }
    }

    // 2. Build edges from adjacent words
    for (int i = 0; i + 1 < (int)words.size(); ++i) {
        string &w1 = words[i];
        string &w2 = words[i + 1];

        int len = min(w1.size(), w2.size());
        int j = 0;
        for (; j < len; ++j) {
            if (w1[j] != w2[j]) {
                char u = w1[j], v = w2[j];
                adj[u].push_back(v);
                indegree[v]++;
                break;
            }
        }

        // Invalid prefix case: "abcd" before "ab"
        if (j == len && w1.size() > w2.size()) {
            return "";
        }
    }

    // 3. Topological sort (Kahn's)
    queue<char> q;
    for (auto &p : indegree) {
        if (p.second == 0) {
            q.push(p.first);
        }
    }

    string order;
    while (!q.empty()) {
        char u = q.front(); q.pop();
        order.push_back(u);
        for (char v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If there was a cycle
    if (order.size() != indegree.size()) {
        return "";
    }
    return order;
        
    }
};
