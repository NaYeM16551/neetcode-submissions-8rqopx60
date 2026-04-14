class Solution {
    pair<int,int> getDistinction(const string&word1,const string& word2)
    {
        int i=0;
        for(;i<min(word1.size(),word2.size());++i)
        {
            if(word1[i]!=word2[i])
               return {word1[i]-97,word2[i]-97};
        }
       // cout<<i<<endl;
        if(word1.size()==word2.size() or i<word2.size())
          return {word1[word1.size()-1]-97,word2[i]-97};
        else if(word1.size()>word2.size())
         return {-5,-5};  

        return {-1,-1};

    }
public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>>adj(26);
        vector<int>indegree(26,-1);

        set<string> st;

        for(auto& word : words)
        {
            st.insert(word);
            for(auto& ch : word)
            {
                    indegree[ch-97]=0;
            }
        }

        // if(st.size()==1)
        // {
        //     auto it = st.begin();
        //     string str = *it;
        //     sort(str.begin(),str.end());

        //     if(str[0]==str[str.size()-1])return to_string(str[0]);
            
        // }
       // bool flag = false;
        for(int i=0;i<(int)words.size()-1;++i)
        {
            string word1 = words[i];
            string word2 = words[i+1];

            auto res = getDistinction(word1,word2);
           // cout<<res.first<<endl;
           if(res.first==-5)return {};
            if(res.first==-1 || res.first==res.second)continue;
            
            

            adj[res.first].push_back(res.second);
            indegree[res.second]++;
            //flag=true;

        }

       // if(!flag)return {};
        

        queue<int> q;
        string ans="";

        for(int i=0;i<26;++i)
        {
            if(!indegree[i])q.push(i);
        }

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            ans+=(node+97);

            for(auto& child : adj[node])
            {
                indegree[child]--;
                if(!indegree[child])q.push(child);
            }
        }

        for(int i=0;i<26;++i)
        {
            if(indegree[i]>0)return {};
        }
        return ans;
        
    }
};
