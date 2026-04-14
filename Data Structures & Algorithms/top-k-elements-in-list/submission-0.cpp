class Solution {
  vector<int> countingSort(vector<pair<int, int>>& freq, int k) {
    int n = freq.size();

    int maxFreq = 0;
    for (auto& p : freq) {
      maxFreq = max(maxFreq, p.first);
    }


    vector<int> count(maxFreq + 1, 0);
    for (auto& p : freq) {
      count[p.first]++;
    }

    
    for (int i = 1; i <= maxFreq; ++i) {
      count[i] += count[i - 1];
    }

    vector<pair<int, int>> output(n);
    for (int i = n - 1; i >= 0; --i) {
      int freqValue = freq[i].first;
      int pos = count[freqValue] - 1;
      output[pos] = freq[i];
      count[freqValue]--;
    }

   
    vector<int> ans;
    for (int i = n - 1; i >= 0 && ans.size() < k; --i) {
      ans.push_back(output[i].second);
    }

    return ans;
  }

public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (auto& num : nums) {
      mp[num]++;
    }

    vector<pair<int, int>> freq;
    for (auto& p : mp) {
      freq.push_back({p.second, p.first}); 
    }

    return countingSort(freq, k);
  }
};