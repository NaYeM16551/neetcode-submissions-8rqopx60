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
    int i = 0;

    while (i < s.size()) {
        int idx = s.find('#', i);

        int len = stoi(s.substr(i, idx - i));

        string word = s.substr(idx + 1, len);
        ans.push_back(word);

        i = idx + 1 + len; // move to next block
    }

    return ans;
}
};
