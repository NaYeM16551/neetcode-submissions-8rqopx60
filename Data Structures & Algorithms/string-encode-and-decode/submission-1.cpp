class Solution {
public:

    string encode(vector<string>& strs) {
       int n = strs.size();

       string encoded = "";

       for(int i=0;i<n;++i)
       {
        int len = strs[i].size();
        encoded+=to_string(len)+"#";
        encoded+=strs[i];

       }
       return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int len;

        int lastIdx = 0;

        for(int i=0;i<s.size();++i)
        {
            auto idx = s.find('#',i);
            len = stoi(s.substr(i,idx));

            ans.push_back(s.substr(idx+1,len));

            i=idx+len;
        }
        return ans;
    }
};
