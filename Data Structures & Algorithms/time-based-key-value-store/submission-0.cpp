class TimeMap {
    map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
        auto v = mp[key];

        int l = 0, h =v.size()-1;

    string ans = "";

   

        while(l<=h)
        {
            int mid = l +(h-l)/2;

            if(v[mid].first<=timestamp)
            {
                ans=v[mid].second;
                l=mid+1;
            }
            else
             h=mid-1;
        }
        return ans;
    }
};
